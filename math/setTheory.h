#pragma once
#include<set>
//���Ա����뼯���е�Ԫ�أ�ÿһ��Ԫ��Ҫ�����Լ��ı�ʶ
class element{
	//�����ú����ж�����Ԫ���Ƿ�Ϊͬһ��Ԫ��
	virtual int getID();
};
//�������ж����һ������
class setTheory
{
	//�洢���е��ڲ�Ԫ��
	std::set<element*> obj;
public:
	
	setTheory();
	~setTheory();
	
	setTheory Union(setTheory& fs);
	setTheory intersection(setTheory& fs);
	setTheory complement(setTheory& fs);
};

