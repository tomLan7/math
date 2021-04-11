#pragma once
#include"number_complex.h"
#include"monomial.h"
#include"ColumnVector.h"
#include"RowVector.h"
#include<initializer_list>
#include"Determinant.h"
template<typename T>
class Matrix//����
{
	//������� ��һ����������ɵ�������
	RowVector<ColumnVector<T>> content
	friend Determinant;
public:
	Matrix(const T*, int countColumn);//����������ʼ������������������Զ�����
	Matrix(initializer_list<initializer_list<T>>);//����������ʼ������������������Զ�����
	Matrix(int level);//n�׿վ���
	Matrix getAdjoint();//��ð������
	Matrix getInverse();//�����
	Determinant getDeterminant();//��ȡ����ʽ
	monomial<Matrix> getAlgebraicCofactor(int r, int c);//���ָ��Ԫ�صĴ�������ʽ����
	Matrix	getCofactor(int r,int c);//���ָ��Ԫ�ص�����ʽ����
	Matrix& operator*=(int);
	Matrix& operator+=(Matrix&);
	Matrix& operator*=(Matrix&);
	Matrix& operator/(number_complex&);
	int getRank();//���ؾ�����ȣ���-------------------------------------------------��δʵ��
	int getRow();//��������
	int getCol();//��������
	~Matrix();
	Matrix operator()(Matrix vec);	//�Ծ������Ա任
};
Matrix operator*(number_complex&, Matrix&);

