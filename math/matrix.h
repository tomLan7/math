#pragma once
#include"number_complex.h"
#include"monomial.h"
class Matrix;
class Determinant{//����ʽ
	int order;//����
	number_complex *data;//����
	int numb;//��ǰԪ����,���к��е����,���㴴������,
public:
	bool addElement(number_complex&);//���һ��Ԫ�أ������δ�����Ԫ�صĻ�,�ͻᱻ��䣬���˳���Ǵ��ϵ��´�����
	Determinant(number_complex*,int row,int col);
	Determinant(Matrix&);
	number_complex getValue();//��ȡ����ʽ��ֵ���������ʽ����,������չ���ټ���
	monomial<Determinant> deploy(int x, int y);
};

class Matrix//����
{
	number_complex* data;
	int row;//����
	int col;//����
	friend Determinant;
public:
	Matrix(number_complex*, int r, int c);//������к���
	Matrix(int level, number_complex& value);//����,�����������Խ��߳�ʼ��
	Matrix();//�վ���
	Matrix getAdjoint();//��ð������
	Matrix getInverse();//�����
	number_complex getDeterminantValue();//�������ʽ��ֵ,����ֵӦ����һ������
	Determinant getDeterminant();//��ȡ����ʽ
	monomial<Matrix> getAlgebraicCofactor(int r, int c);//���ָ��Ԫ�صĴ�������ʽ����
	Matrix	getCofactor(int r,int c);//���ָ��Ԫ�ص�����ʽ����
	Matrix operator*(int);
	Matrix operator+(Matrix&);
	Matrix operator*(Matrix&);
	Matrix operator/(number_complex&);
	int getRank();//���ؾ�����ȣ���-------------------------------------------------��δʵ��
	int getRow();//��������
	int getCol();//��������
	~Matrix();
	Matrix operator()(Matrix vec);	//�Ծ������Ա任
};
Matrix operator*(number_complex&, Matrix&);

