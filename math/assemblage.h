#pragma once
#include<vector>
#include<functional>
#include"proposition.h"
class element{//每个对象都是一个元素,所有可放在集合中的元素都要直接或间接继承元素类
	virtual void* getFeatures();//返回特征,通常是返回地址，也可以返回别的，在存放集合元素中，不会添加特征相同的对象
	//{return (void*)this;
	//}
	bool equals(element &);//比较两个element是否相同
};

class assemblage:element//集合,集合也可以在其他集合中
{
	std::vector<element*> data;//存着所有单个元素,朴素集合论的元素所在处
	std::vector<proposition*> v;//存着所有命题，传入一个元素，判断是否在其中，先看是不是在data中，不在再看满足不满足定义
public:
	static assemblage intersectionOperator(assemblage&, assemblage&);//两个集合取交集
	static assemblage unionOperator(assemblage&, assemblage&);//两个集合取并集
	static assemblage differenceOperator(assemblage&, assemblage&);//两个集合取差，第一个集合但不是第二个集合的元素,
	bool isEmyty();//是否为空集,是空集返回true
	bool addElement(element*);//添加元素,会检查，不会添加重复元素，如果元素重复会添加失败返回false

	assemblage();
	~assemblage();
};

