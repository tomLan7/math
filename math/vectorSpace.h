#pragma once
#include"integer.hpp"
class vectorSpace//�����ռ�,����ӷ������˲�������
{
public:
	virtual vectorSpace operator+(vectorSpace&);//�ӷ�
	virtual vectorSpace operator*(const integer&);//����
	vectorSpace();
	~vectorSpace();
};

