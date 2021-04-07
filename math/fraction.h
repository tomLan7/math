#pragma once
#include "number_real.h"
#include "integer.hpp"
#include "tool.h"
#include<iostream>
//可以存储一个有理数的框子，有理数,可以由分数，两个整数存储,根据有理数的定义,可以存储一个有理数,
class fraction{
	//第一个是分子,第二个是分母
	Vec2<integer> data;
	//是否自动化简，每次运算后自动化简，默认是true，
	bool autoSimple;
public:
	//设置是否自动化简
	void setAutoSimple(const bool);
	bool getAutoSimple();//自动化简
	//产生一个0
	fraction();
	//将一个long包装成分数
	fraction(long);
	//将一个double包装成分数
	fraction(double);
	//将一个integer包装成分数（分母为1)
	fraction(const integer&);
	fraction(const integer&,const integer&);
	//化简，如果化简完后确保是最小的
	fraction& Simplification();
	//返回分母的值
	integer& getDenominator();
	//返回分子的值
	integer& getMolecule();
	//向上取整
	integer getCeil();
	//向下取整
	integer getfloor();
	~fraction();
	//数乘
	fraction operator*(fraction&);
	//加法
	fraction operator+(fraction&);
};

std::ostream& operator<<(std::ostream&,fraction& i);