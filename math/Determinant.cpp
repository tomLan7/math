#include "Determinant.h"



template<typename T> T Determinant<T>::get(int x, int y) {//Õ¹¿ª
	return data[x*order+y];
}