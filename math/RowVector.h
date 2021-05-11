#pragma once
#include<vector>
#include<string>
#include<ostream>
#include<sstream>
#include"VectorException.h"
template<class T> class ColumnVector;
template<typename T=double>
class RowVector:public std::vector<T>
{
public:
	RowVector<T>& operator*=(const T& k) {
		
		for (auto & i:*this) {
			i *= k;
		}
		return *this;
	}
	RowVector<T> operator*(const T& k)const {
		auto tem = *this;
		return tem *= k;
	}
	RowVector<T>& operator+=(const RowVector<T>& or) {
		if (size()!=or.size()) {
			throw DimensionNotMatch("行向量加法");
		}
		for* (int i = 0; i < size(); i++) {
			at(i) += or .at(i);
		}
		return *this;
	}
	RowVector<T> operator+(const RowVector<T>& k) const{
		if (size()!=k.size()) {
			throw DimensionNotMatch("行向量加法");
		}
		auto tem = *this;
		return tem += k;
	}
	
	T operator*(const ColumnVector<T>& k)const{
		if (size()!= k.size()) {
			throw DimensionNotMatch("行向量乘列向量时维度错误");
		}
		T tem{0};
		for (int i = 0; i < size();i++) {
			tem += (at(i)*k[i]);
		}
		return tem;
	}
	std::string toString()const{
		std::ostringstream os;
		os << "(";
		for (auto& j : *this) {
			os << j << ",\t";
		}
		os << ")\n";
		return os.str();
	}
	RowVector<T> operator-()const{
		auto tem = *this;
		for (size_t i = 0; i < size(); i++) {
			tem[i] = -tem[i];
		}
		return tem;
	}
	using vector::vector;
};
template<class T> std::ostream& operator<<(std::ostream& out, const RowVector<T>& m) {
	out << m.toString();
	return out;
}

template<class T> 	RowVector<T> operator*(const T& d, const RowVector<T>& k) {
	return k * d;
}
template<class T> 	RowVector<T> operator+(const T& d, const RowVector<T>& k) {
	return k + d;
}