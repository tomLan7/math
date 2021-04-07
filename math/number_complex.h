#pragma once
#include "number_real.h"
class number_complex
{
	number_real dataX;//ʵ��
	number_real dataY;//�鲿
public:
	number_complex();//Ĭ��Ϊ0
	number_complex(number_real& x,number_real& y);//Ĭ��Ϊ0
	number_complex(number_real& x);
	~number_complex();
	number_complex getConjugate();//��ù����
	number_complex& operator=(number_complex&);
	number_complex operator*(int);
	number_complex operator*(number_complex&);
	number_complex& operator*=(int);
	number_complex operator+(number_complex&);
	number_complex& operator+=(number_complex&);
	number_complex operator/(number_complex&);
	number_complex operator/(number_real&);
};

