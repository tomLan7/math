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
	}//level�� �����
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
	Matrix<T>& operator*=(double k) {
		for (auto& i: _content) {
			i *= k;
		}
		return *this;
	}
	Matrix<T>& operator+=(Matrix<T>& om) {

		for (size_t i = 0; i < om.getCol();i++) {
			_content[i] += om[i];
		}
		return *this;
	}
	bool operator==(Matrix<T>& om) {
		
		for (int i = 0; i < om.getCol(); i++) {
			if (_content[i]!=om[i]) {
				return false;
			}
		}
		return true;
	}
	Matrix& operator*=(Matrix&);
	Matrix& operator/(T&&);
	ColumnVector<T>& operator[](size_t index) {
		return _content[index];
	}
	int getRank();//���ؾ�����ȣ���-------------------------------------------------��δʵ��
	//��������
	int getRow() {
		return _content[0].size();
	}
	//��������
	int getCol() {
		return _content.size();
	}
	Matrix operator()(Matrix vec);	//�Ծ������Ա任
};
template<class T> std::ostream& operator<<(std::ostream& out, Matrix<T> m) {
	out << m.toString();
	return out;
}