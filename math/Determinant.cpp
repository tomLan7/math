#include "Determinant.h"



template<typename T> T Determinant<T>::get(int x, int y) {//չ��
	return data[x*order+y];
}