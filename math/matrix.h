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
	Matrix(const std::initializer_list<std::initializer_list<T>>& list)
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
	std::string toString()const{
		std::ostringstream os;
		for (int i = 0; i < getRow(); i++) {
			os << "|";
			for (int j = 0; j < getCol(); j++) {
				os << _content[j][i]<<",\t";
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
	Matrix<T>& operator*=(const T& k) {
		for (auto& i: _content) {
			i *= k;
		}
		return *this;
	}
	Matrix<T>& operator+=(const Matrix<T>& om) {

		for (size_t i = 0; i < om.getCol();i++) {
			_content[i] += om[i];
		}
		return *this;
	}
	bool operator==(const Matrix<T>& om) {
		
		for (unsigned int i = 0; i < om.getCol(); i++) {
			if (_content[i]!=om[i]) {
				return false;
			}
		}
		return true;
	}
	Matrix& operator*=(const Matrix&) {

	}
	Matrix& operator/=(const T&);
	ColumnVector<T>& operator[](size_t index){
		return _content[index];
	}
	const ColumnVector<T>& operator[](size_t index)const {
		return _content[index];
	}
	int getRank();//���ؾ�����ȣ���-------------------------------------------------��δʵ��
	//��������
	int getRow()const {
		return _content[0].size();
	}
	//��������
	int getCol() const{
		return _content.size();
	}
	Matrix operator()(const Matrix& vec);	//�Ծ������Ա任
};
template<class T> std::ostream& operator<<(std::ostream& out, const Matrix<T>& m) {
	out << m.toString();
	return out;
}

