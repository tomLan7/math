#pragma once
#include"number_complex.h"
template<class T> class monomial//单项式
{
public:
	number_complex coefficient;//系数
	T data;//本质
	monomial(number_complex&, T);//全新
	monomial(T);//系数为1
	monomial();//0

};

class polynomial{//多项式
};