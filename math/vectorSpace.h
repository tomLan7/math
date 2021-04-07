#pragma once
#include"integer.hpp"
class vectorSpace//向量空间,满足加法和数乘不变类型
{
public:
	virtual vectorSpace operator+(vectorSpace&);//加法
	virtual vectorSpace operator*(const integer&);//数乘
	vectorSpace();
	~vectorSpace();
};

