#pragma once
#include<vector>
class Statistics
{
public:
	Statistics();
	~Statistics();
};
//ͳ��ѧ
class distribution{
	static distribution createDistribution(std::vector<int>);//����һ�����ݣ�����һ���ֲ����ֲ������˸��ʵķֲ�
	int getRandom();//�ø÷ֲ�����һ�������
};

class point{//������
	bool equals(point&);//�Ƚ������������Ƿ���ͬ
};
class event{//�¼�����
public:
	event sum(event&);//ȡ�Ͳ���
	event operator+(event&);//ͬ��
	event product(event&);//ȡ������
	event operator*(event&);//ͬ��
	event overturn();//ȡ�ǲ���   
	event operator!();//ͬ��
	event subtract(event&);//ȡ�����
	event operator-(event&);//ͬ��

	enum rule{ �оٷ�, ������, ���䷨ };//��ʱֻ���оٷ�
	bool include(event&);//�鿴һ���Ƿ������һ���¼�
	bool include(point&);//�鿴�Ƿ����һ����������
private:
	std::vector<point&> obj;//�оٷ���ӣ������ظ�
public:
	bool addPoint(point&);//���һ��������,�ɹ�����true��ʧ�ܷ���false
	int getNumb();//�������������
	bool equals(event&);//ͬ��
	bool operator==(event&);//�Ƚ������¼��Ƿ���ȫ��ͬ
};
class eventGroup{//�¼��顢
	std::vector<event&> obj;
};