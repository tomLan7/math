#pragma once
#include<vector>
template<typename T>class Martix;
template<typename T>
class Determinant {//n阶行列式有意义
	int order;//阶数
	std::vector<T> data;//本质元素
public:
	bool addElement(T&& obj);//添加一个元素，如果有未定义的元素的话,就会被填充，填充顺序是从第一列上到下.
	Determinant(const T*,int n_order);
	//Determinant(Matrix<T>& mtx);

	//获取行列式的值，如果行列式过多,则考虑先展开再计算
	T getValue();
	T get(int x, int y);
};