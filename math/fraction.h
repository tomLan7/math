#pragma once
#include "number_real.h"
#include "integer.hpp"
#include "tool.h"
#include<iostream>
//���Դ洢һ���������Ŀ��ӣ�������,�����ɷ��������������洢,�����������Ķ���,���Դ洢һ��������,
class fraction{
	//��һ���Ƿ���,�ڶ����Ƿ�ĸ
	Vec2<integer> data;
	//�Ƿ��Զ�����ÿ��������Զ�����Ĭ����true��
	bool autoSimple;
public:
	//�����Ƿ��Զ�����
	void setAutoSimple(const bool);
	bool getAutoSimple();//�Զ�����
	//����һ��0
	fraction();
	//��һ��long��װ�ɷ���
	fraction(long);
	//��һ��double��װ�ɷ���
	fraction(double);
	//��һ��integer��װ�ɷ�������ĸΪ1)
	fraction(const integer&);
	fraction(const integer&,const integer&);
	//��������������ȷ������С��
	fraction& Simplification();
	//���ط�ĸ��ֵ
	integer& getDenominator();
	//���ط��ӵ�ֵ
	integer& getMolecule();
	//����ȡ��
	integer getCeil();
	//����ȡ��
	integer getfloor();
	~fraction();
	//����
	fraction operator*(fraction&);
	//�ӷ�
	fraction operator+(fraction&);
};

std::ostream& operator<<(std::ostream&,fraction& i);