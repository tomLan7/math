#pragma once
#include<vector>
#include<set>
//ģ����
class FuzzySet
{
public:
	//std::set<std::pair<,double>> all;//�����洢ÿ��ֵ
	FuzzySet();
	~FuzzySet();

	//��
	FuzzySet Union(FuzzySet& fs);
	//��
	FuzzySet intersection(FuzzySet& fs);
	//��
	FuzzySet complement(FuzzySet& fs);
};

