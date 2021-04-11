#pragma once
#include<set>
//可以被放入集合中的元素，每一个元素要求有自己的标识
class element{
	//依赖该函数判断两个元素是否为同一个元素
	virtual int getID();
	//判断两个元素是否相同
	virtual bool equals(element* e);
	
};
//集合论中定义的一个集合
class SetTheory
{
	//存着所有单个元素,朴素集合论的元素所在处
	std::set<element*> obj;
	//存着所有命题，传入一个元素，判断是否在其中，先看是不是在data中，不在再看满足不满足定义
	//std::vector<proposition*> v;
public:
	
	SetTheory();
	~SetTheory();
	bool isContain(element* e);
	SetTheory& Union(SetTheory& fs);
	SetTheory& intersection(SetTheory& fs);
	SetTheory& difference(SetTheory& fs);
	bool isEmpty();//是否为空集,是空集返回true
	bool addElement(element* e);//添加元素,会检查，不会添加重复元素，如果元素重复会添加失败返回false
};

