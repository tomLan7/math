#pragma once
#include<vector>
#include<string>
#include<ostream>
#include<sstream>
template<typename T>
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
		assert(size()==or.size());
		for* (int i = 0; i < size(); i++) {
			at(i) += or .at(i);
		}
		return *this;
	}
	RowVector<T> operator+(const RowVector<T>& k) const{
		auto tem = *this;
		return tem += k;
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