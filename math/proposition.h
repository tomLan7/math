#include<functional>
#include<vector>
class proposition{//������,��߿����ж�������ж�
	std::vector<proposition*> obj1;//�������ⶼ���㣬�Ż�����
	virtual bool getBool();//���ظ������Ƿ�Ϊ��
	bool operator||(proposition&);
	bool operator&&(proposition&);
	bool operator!();
};