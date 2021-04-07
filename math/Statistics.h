#pragma once
#include<vector>
class Statistics
{
public:
	Statistics();
	~Statistics();
};
//统计学
class distribution{
	static distribution createDistribution(std::vector<int>);//传入一组数据，生成一个分布，分布体现了概率的分布
	int getRandom();//用该分布生成一个随机数
};

class point{//样本点
	bool equals(point&);//比较两个样本点是否相同
};
class event{//事件集合
public:
	event sum(event&);//取和操作
	event operator+(event&);//同上
	event product(event&);//取积操作
	event operator*(event&);//同上
	event overturn();//取非操作   
	event operator!();//同上
	event subtract(event&);//取差操作
	event operator-(event&);//同上

	enum rule{ 列举法, 特征法, 区间法 };//暂时只有列举法
	bool include(event&);//查看一个是否包含另一个事件
	bool include(point&);//查看是否包含一个用样本点
private:
	std::vector<point&> obj;//列举法添加，不会重复
public:
	bool addPoint(point&);//添加一个样本点,成功返回true，失败返回false
	int getNumb();//返回样本点个数
	bool equals(event&);//同下
	bool operator==(event&);//比较两个事件是否完全相同
};
class eventGroup{//事件组、
	std::vector<event&> obj;
};