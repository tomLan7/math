#pragma once
#include<set>
//可以被放入集合中的元素，每一个元素要求有自己的标识
class element{
	//依赖该函数判断两个元素是否为同一个元素
	virtual int getID();
};
//集合论中定义的一个集合
class setTheory
{
	//存储所有的内部元素
	std::set<element*> obj;
public:
	
	setTheory();
	~setTheory();
	
	setTheory Union(setTheory& fs);
	setTheory intersection(setTheory& fs);
	setTheory complement(setTheory& fs);
};

