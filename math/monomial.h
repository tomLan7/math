#pragma once
#include"number_complex.h"
template<class T> class monomial//����ʽ
{
public:
	number_complex coefficient;//ϵ��
	T data;//����
	monomial(number_complex&, T);//ȫ��
	monomial(T);//ϵ��Ϊ1
	monomial();//0

};

class polynomial{//����ʽ
};