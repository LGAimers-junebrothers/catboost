package ai.catboost.spark

import collection.JavaConverters._
import collection.mutable
import collection.Set

import org.apache.spark.sql._

import org.junit.{Assert,Test}


class PoolTest {
  def getGroupedDatasetAsHashMap(data: DataFrame, groupIdCol: String) : mutable.HashMap[Long, Set[Row]] = {
    val groupIdIdx = data.schema.fieldIndex(groupIdCol)
    val result = new mutable.HashMap[Long, Set[Row]]
    data.rdd.groupBy(row => row.getLong(groupIdIdx)).toLocalIterator.foreach{
      case (groupId, rows) => {
        val groupRowsSet = new mutable.HashSet[Row]
        for (row <- rows) {
          groupRowsSet += row
        }
        result += (groupId -> groupRowsSet)
      }
    }
    result
  }
  
  def assertIsSubsetWithGroups(data: DataFrame, subsetData: DataFrame, groupIdCol: String) = {
    val dataAsHashMap = getGroupedDatasetAsHashMap(data, groupIdCol)
    val subsetDataAsHashMap = getGroupedDatasetAsHashMap(subsetData, groupIdCol)
    for ((groupId, rowsSet) <- subsetDataAsHashMap) {
      Assert.assertTrue(dataAsHashMap.contains(groupId))
      Assert.assertTrue(dataAsHashMap(groupId).equals(rowsSet))
    }
  }
  
  def assertIsSubset(data: Pool, subsetData: Pool) = {
    if (data.isDefined(data.groupIdCol)) {
      Assert.assertTrue(subsetData.isDefined(subsetData.groupIdCol))
      Assert.assertTrue(subsetData.getGroupIdCol.equals(data.getGroupIdCol))
      assertIsSubsetWithGroups(data.data, subsetData.data, data.getGroupIdCol)
      if (data.pairsData != null) {
        Assert.assertTrue(subsetData.pairsData != null)
        assertIsSubsetWithGroups(data.pairsData, subsetData.pairsData, "groupId")
      }
    } else {
      val dataAsSet = data.data.toLocalIterator.asScala.toSet
      val subsetDataAsSet = subsetData.data.toLocalIterator.asScala.toSet
      Assert.assertTrue(subsetDataAsSet.subsetOf(dataAsSet))
    }
  }
  
  @Test
  @throws(classOf[Exception])
  def testSampleSimple() {
    val spark = TestHelpers.getOrCreateSparkSession(TestHelpers.getCurrentMethodName)
    val data = PoolTestHelpers.createRandomPool(
      spark, 
      floatFeatureCount=10,
      catFeatureCount=0,
      objectCount=100
    )
    val subsetData = data.sample(0.5)
    assertIsSubset(data, subsetData)
  }
  
  @Test
  @throws(classOf[Exception])
  def testSampleWithGroups() {
    val spark = TestHelpers.getOrCreateSparkSession(TestHelpers.getCurrentMethodName)
    val data = PoolTestHelpers.createRandomPool(
      spark, 
      floatFeatureCount=10,
      catFeatureCount=0,
      groupCount=100,
      expectedGroupSize=5
    )
    val subsetData = data.sample(0.3)
    assertIsSubset(data, subsetData)
  }
  
  @Test
  @throws(classOf[Exception])
  def testSampleWithPairs() {
    val spark = TestHelpers.getOrCreateSparkSession(TestHelpers.getCurrentMethodName)
    val data = PoolTestHelpers.createRandomPool(
      spark, 
      floatFeatureCount=3,
      catFeatureCount=6,
      groupCount=100,
      expectedGroupSize=8,
      pairsFraction=0.4
    )
    val subsetData = data.sample(0.3)
    assertIsSubset(data, subsetData)
  }
  
  @Test
  @throws(classOf[Exception])
  def testSampleWithPairsWithWeights() {
    val spark = TestHelpers.getOrCreateSparkSession(TestHelpers.getCurrentMethodName)
    val data = PoolTestHelpers.createRandomPool(
      spark, 
      floatFeatureCount=2,
      catFeatureCount=5,
      groupCount=100,
      pairsFraction=0.3,
      pairsHaveWeight=true
    )
    val subsetData = data.sample(0.7)
    assertIsSubset(data, subsetData)
  }
}