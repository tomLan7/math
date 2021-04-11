#pragma once
#include"number_complex.h"
#include"monomial.h"
#include"ColumnVector.h"
#include"RowVector.h"
#include<initializer_list>
#include"Determinant.h"
template<typename T>
class Matrix//矩阵
{
	//矩阵就是 由一个列向量组成的行向量
	RowVector<ColumnVector<T>> content
	friend Determinant;
public:
	Matrix(const T*, int countColumn);//由数组来初始化。数组和列数，会自动导入
	Matrix(initializer_list<initializer_list<T>>);//由数组来初始化。数组和列数，会自动导入
	Matrix(int level);//n阶空矩阵
	Matrix getAdjoint();//获得伴随矩阵
	Matrix getInverse();//获得逆
	Determinant getDeterminant();//获取行列式
	monomial<Matrix> getAlgebraicCofactor(int r, int c);//获得指定元素的代数余子式矩阵
	Matrix	getCofactor(int r,int c);//获得指定元素的余子式矩阵
	Matrix& operator*=(int);
	Matrix& operator+=(Matrix&);
	Matrix& operator*=(Matrix&);
	Matrix& operator/(number_complex&);
	int getRank();//返回矩阵的秩，，-------------------------------------------------暂未实现
	int getRow();//返回行数
	int getCol();//返回列数
	~Matrix();
	Matrix operator()(Matrix vec);	//对矩阵线性变换
};
Matrix operator*(number_complex&, Matrix&);

