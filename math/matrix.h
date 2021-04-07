#pragma once
#include"number_complex.h"
#include"monomial.h"
class Matrix;
class Determinant{//行列式
	int order;//阶数
	number_complex *data;//本质
	int numb;//当前元素数,先行后列的添加,方便创建对象,
public:
	bool addElement(number_complex&);//添加一个元素，如果有未定义的元素的话,就会被填充，填充顺序是从上到下从左到右
	Determinant(number_complex*,int row,int col);
	Determinant(Matrix&);
	number_complex getValue();//获取行列式的值，如果行列式过多,则考虑先展开再计算
	monomial<Determinant> deploy(int x, int y);
};

class Matrix//矩阵
{
	number_complex* data;
	int row;//行数
	int col;//列数
	friend Determinant;
public:
	Matrix(number_complex*, int r, int c);//数组和行和列
	Matrix(int level, number_complex& value);//阶数,可以设置主对角线初始化
	Matrix();//空矩阵
	Matrix getAdjoint();//获得伴随矩阵
	Matrix getInverse();//获得逆
	number_complex getDeterminantValue();//获得行列式的值,返回值应该是一个复数
	Determinant getDeterminant();//获取行列式
	monomial<Matrix> getAlgebraicCofactor(int r, int c);//获得指定元素的代数余子式矩阵
	Matrix	getCofactor(int r,int c);//获得指定元素的余子式矩阵
	Matrix operator*(int);
	Matrix operator+(Matrix&);
	Matrix operator*(Matrix&);
	Matrix operator/(number_complex&);
	int getRank();//返回矩阵的秩，，-------------------------------------------------暂未实现
	int getRow();//返回行数
	int getCol();//返回列数
	~Matrix();
	Matrix operator()(Matrix vec);	//对矩阵线性变换
};
Matrix operator*(number_complex&, Matrix&);

