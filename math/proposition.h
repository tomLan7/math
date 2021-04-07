#include<functional>
#include<vector>
class proposition{//命题类,里边可以有多个布尔判断
	std::vector<proposition*> obj1;//所有命题都满足，才会满足
	virtual bool getBool();//返回该命题是否为真
	bool operator||(proposition&);
	bool operator&&(proposition&);
	bool operator!();
};