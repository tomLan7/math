#pragma once
#include"ColumnVector.h"
#include"RowVector.h"
#include<initializer_list>
#include<string>
#include<ostream>
#include<sstream>

template<typename T>
class Matrix//矩阵
{
protected:
	//矩阵就是 由一个列向量组成的行向量
	RowVector<ColumnVector<T>> _content;
public:
	Matrix(const T*, int countColumn);//由数组来初始化。数组和列数，会自动导入
	Matrix(std::initializer_list<std::initializer_list<T>> list)
	{
		_content.resize(list.size());
		auto iter = _content.begin();
		for (auto& i : list) {
			(*iter++).assign(i.begin(), i.end());
		}
	}//由数组来初始化。数组和列数，会自动导入
	Matrix(int level)
	{
		_content.resize(level);
		for (auto& i : _content) {
			i.resize(level);
		}
	}
	std::string toString() {
		std::ostringstream os;
		for (auto&i: _content) {
			os << "|";
			for (auto& j:i) {
				os << j<<",\t";
			}
			os << "|\n";
		}
		return os.str();
	}
	//n阶空矩阵
	Matrix getAdjoint();//获得伴随矩阵
	Matrix getInverse();//获得逆
	//Determinant<T> getDeterminant();//获取行列式
	//获得指定元素的代数余子式矩阵
	//monomial<Matrix> getAlgebraicCofactor(int r, int c);
	Matrix	getCofactor(int r,int c);//获得指定元素的余子式矩阵
	//数乘
	Matrix& operator*=(int k) {
		for (auto& i: _content) {
			i *= k;
		}
	}
	Matrix& operator+=(Matrix& om) {

		for (int i = 0; i < om.size();i++) {
			i *= k;
		}
	}
	Matrix& operator*=(Matrix&);
	Matrix& operator/(T&&);
	int getRank();//返回矩阵的秩，，-------------------------------------------------暂未实现
	int getRow();//返回行数
	int getCol();//返回列数
	Matrix operator()(Matrix vec);	//对矩阵线性变换
};
