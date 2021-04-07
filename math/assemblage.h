#pragma once
#include<vector>
#include<functional>
#include"proposition.h"
class element{//ÿ��������һ��Ԫ��,���пɷ��ڼ����е�Ԫ�ض�Ҫֱ�ӻ��Ӽ̳�Ԫ����
	virtual void* getFeatures();//��������,ͨ���Ƿ��ص�ַ��Ҳ���Է��ر�ģ��ڴ�ż���Ԫ���У��������������ͬ�Ķ���
	//{return (void*)this;
	//}
	bool equals(element &);//�Ƚ�����element�Ƿ���ͬ
};

class assemblage:element//����,����Ҳ����������������
{
	std::vector<element*> data;//�������е���Ԫ��,���ؼ����۵�Ԫ�����ڴ�
	std::vector<proposition*> v;//�����������⣬����һ��Ԫ�أ��ж��Ƿ������У��ȿ��ǲ�����data�У������ٿ����㲻���㶨��
public:
	static assemblage intersectionOperator(assemblage&, assemblage&);//��������ȡ����
	static assemblage unionOperator(assemblage&, assemblage&);//��������ȡ����
	static assemblage differenceOperator(assemblage&, assemblage&);//��������ȡ���һ�����ϵ����ǵڶ������ϵ�Ԫ��,
	bool isEmyty();//�Ƿ�Ϊ�ռ�,�ǿռ�����true
	bool addElement(element*);//���Ԫ��,���飬��������ظ�Ԫ�أ����Ԫ���ظ������ʧ�ܷ���false

	assemblage();
	~assemblage();
};

