#pragma once
#include<vector>
template<typename T>
class RowVector:public std::vector<T>
{
public:
	RowVector<T>& operator*=(double k) {
		
		for (auto & i:*this) {
			i *= k;
		}
		return *this;
	}
	RowVector<T>& operator+=(RowVector<T>& or) {
		assert(size()==or.size());
		for* (int i = 0; i < size(); i++) {
			at(i) += or .at(i);
		}
		return *this;
	}
};

