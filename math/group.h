#include"assemblage.h"
#include<functional>
class Semigroup{//半群
	std::function<bool(element*, element*)> f;//一个代数运算
	assemblage set;//一个集合
	public:
};
class group:Semigroup{//群
public:
	element* getE();//获得单位元
	element* getInterval(element*);//获得逆元
};