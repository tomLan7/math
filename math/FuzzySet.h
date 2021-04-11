#pragma once
#include<vector>
#include<set>
//模糊集
class FuzzySet
{
public:
	//std::set<std::pair<,double>> all;//向量存储每个值
	FuzzySet();
	~FuzzySet();

	//并
	FuzzySet Union(FuzzySet& fs);
	//交
	FuzzySet intersection(FuzzySet& fs);
	//补
	FuzzySet complement(FuzzySet& fs);
};

