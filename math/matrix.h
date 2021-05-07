#pragma once
#include"ColumnVector.h"
#include"RowVector.h"
#include<initializer_list>
#include<string>
#include<ostream>
#include<sstream>

template<typename T>
class Matrix//����
{
protected:
	//������� ��һ����������ɵ�������
	RowVector<ColumnVector<T>> _content;
public:
	Matrix(const T*, int countColumn);//����������ʼ������������������Զ�����
	Matrix(std::initializer_list<std::initializer_list<T>> list)
	{
		_content.resize(list.size());
		auto iter = _content.begin();
		for (auto& i : list) {
			(*iter++).assign(i.begin(), i.end());
		}
	}//����������ʼ������������������Զ�����
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
	//n�׿վ���
	Matrix getAdjoint();//��ð������
	Matrix getInverse();//�����
	//Determinant<T> getDeterminant();//��ȡ����ʽ
	//���ָ��Ԫ�صĴ�������ʽ����
	//monomial<Matrix> getAlgebraicCofactor(int r, int c);
	Matrix	getCofactor(int r,int c);//���ָ��Ԫ�ص�����ʽ����
	//����
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
	int getRank();//���ؾ�����ȣ���-------------------------------------------------��δʵ��
	int getRow();//��������
	int getCol();//��������
	Matrix operator()(Matrix vec);	//�Ծ������Ա任
};
