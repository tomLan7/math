#pragma once
#include<set>
//���Ա����뼯���е�Ԫ�أ�ÿһ��Ԫ��Ҫ�����Լ��ı�ʶ
class element{
	//�����ú����ж�����Ԫ���Ƿ�Ϊͬһ��Ԫ��
	virtual int getID();
	//�ж�����Ԫ���Ƿ���ͬ
	virtual bool equals(element* e);
	
};
//�������ж����һ������
class SetTheory
{
	//�������е���Ԫ��,���ؼ����۵�Ԫ�����ڴ�
	std::set<element*> obj;
	//�����������⣬����һ��Ԫ�أ��ж��Ƿ������У��ȿ��ǲ�����data�У������ٿ����㲻���㶨��
	//std::vector<proposition*> v;
public:
	
	SetTheory();
	~SetTheory();
	bool isContain(element* e);
	SetTheory& Union(SetTheory& fs);
	SetTheory& intersection(SetTheory& fs);
	SetTheory& difference(SetTheory& fs);
	bool isEmpty();//�Ƿ�Ϊ�ռ�,�ǿռ�����true
	bool addElement(element* e);//���Ԫ��,���飬��������ظ�Ԫ�أ����Ԫ���ظ������ʧ�ܷ���false
};

