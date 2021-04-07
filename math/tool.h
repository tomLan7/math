#pragma once
#include<vector>
#include"integer.hpp"

//通用模板
class tool
{
public:
	tool();
	~tool();
}; 
class mapping{//映射,传入一个返回另一个
	
};
class limitations :mapping{//一个限制条件,传入参数，返回true或者false，true的话就是通过,特殊的mapping
	std::vector<limitations> tree;//限制条件中可以有其他限制条件，需要满足所有限制条件才能返回true
	bool (*user)(...);//一个函数指针,需要满足
	bool tryUser(...);//需要满足本限制条件树中所有限制条件
};
template <class T>
class Vec2{//二维数据的抽象类,类型相同但是是二维,暂不清楚作用和存在意义，自由度是二的数集
	std::vector<T> data;
public:
	Vec2(const T& a, const T& b){
		data.push_back(a);
		data.push_back(b);
	}
	T& first(){
		return data[0];
	}
	T& second(){
		return data[1];
	}
};
template <class T>
class memoryManager{//内存管理者
public:
	static bool equals(T& a, T& b){//比较两个相同类型的对象是否是完全相同
		int len = sizeof(a);
		char* p1 = (char*)(&a);
		char* p2 = (char*)(&b);
		while (len--){
			if (*p1++ != *p2++){
				return false;
			}
		}
		return true;
	}
	
};