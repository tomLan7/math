#pragma once
#include<vector>
//������
template<typename T>
class ColumnVector:public std::vector<T>
{
public:
	ColumnVector<T>& operator*=(const T& k) {

		for (auto& i : *this) {
			i *= k;
		}
		return *this;
	}
	ColumnVector<T>& operator+=(const ColumnVector<T>& or ) {
		if (size()!=or.size()) {
			//TODO: ����׳��쳣
		}
		for(size_t i = 0; i < size(); i++) {
			at(i) += or .at(i);
		}
		return *this;
	}
};
