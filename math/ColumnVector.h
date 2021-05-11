#pragma once
#include<vector>
#include<string>
#include<ostream>
#include<sstream>
#include"VectorException.h"
//列向量
template<typename T=double>
class ColumnVector:public std::vector<T>
{
public:
	ColumnVector<T>& operator*=(const T& k) {

		for (auto& i : *this) {
			i *= k;
		}
		return *this;
	}
	ColumnVector<T> operator*(const T& k)const {
		auto tem = *this;
		return tem*=k;
	}
	ColumnVector<T>& operator+=(const ColumnVector<T>& or ) {
		if (size()!=or.size()) {
			throw DimensionNotMatch("向量加等");
		}
		for(size_t i = 0; i < size(); i++) {
			at(i) += or .at(i);
		}
		return *this;
	}
	ColumnVector<T> operator+(const ColumnVector<T>& k)const{
		if (size()!=k.size()) {
			throw DimensionNotMatch("向量加法");
		}
		auto tem = *this;
		return tem += k;
	}
	std::string toString()const {
		std::ostringstream os;
		for (auto& i : *this) {
			os << "|";
				os << i;
			os << "|\n";
		}
		return os.str();
	}
	ColumnVector<T> operator-() const{
		auto tem = *this;
		for (size_t i = 0; i < size(); i++) {
			tem[i]=-tem[i];
		}
		return tem;
	}
	
	using vector::vector;
};
template<class T> std::ostream& operator<<(std::ostream& out, const ColumnVector<T>& m) {
	out << m.toString();
	return out;
}
//防止7*x乘不了
template<class T> 	ColumnVector<T> operator*(const T& d,const ColumnVector<T>& k) {
	return k*d;
}
template<class T> 	ColumnVector<T> operator+(const T& d, const ColumnVector<T>& k) {
	return k + d;
}