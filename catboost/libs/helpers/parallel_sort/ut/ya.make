

UNITTEST()

SIZE(MEDIUM)

PEERDIR(
    catboost/libs/helpers/parallel_sort
    library/unittest
)

SRCS(
    parallel_sort_ut.cpp
)

END()
