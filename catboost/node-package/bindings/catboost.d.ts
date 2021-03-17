export const DESCRIPTION: string;
export function CreateHandle(): string;

export type CatBoostFloatFeatures = Array<number[]>;
export type CatBoostCategoryFeatures = Array<number[]>|Array<string[]>;

export class Model {
	loadFullFromFile(path: string): void;
	calcPrediction(floatFeatures: CatBoostFloatFeatures, 
		catFeatures: CatBoostCategoryFeatures): number[];
	getFloatFeaturesCount(): number;
	getCatFeaturesCount(): number;
	getTreeCount(): number;
	getDimensionsCount(): number;
}
