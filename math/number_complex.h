#pragma once
#include "number_real.h"
class number_complex
{
	number_real dataX;//实部
	number_real dataY;//虚部
public:
	number_complex();//默认为0
	number_complex(number_real& x,number_real& y);//默认为0
	number_complex(number_real& x);
	~number_complex();
	number_complex getConjugate();//获得共轭复数
	number_complex& operator=(number_complex&);
	number_complex operator*(int);
	number_complex operator*(number_complex&);
	number_complex& operator*=(int);
	number_complex operator+(number_complex&);
	number_complex& operator+=(number_complex&);
	number_complex operator/(number_complex&);
	number_complex operator/(number_real&);
};

