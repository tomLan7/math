#include"assemblage.h"
#include<functional>
class Semigroup{//��Ⱥ
	std::function<bool(element*, element*)> f;//һ����������
	assemblage set;//һ������
	public:
};
class group:Semigroup{//Ⱥ
public:
	element* getE();//��õ�λԪ
	element* getInterval(element*);//�����Ԫ
};