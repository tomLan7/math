#include "Determinant.h"
Determinant::Determinant(number_complex* arr, int r, int c) {
	if (r != c) {
		throw new int;
	}
	this->order = c;
	data = new number_complex[r * c];
	for (int i = r * c - 1; i >= 0; i--) {
		data[i] = arr[i];
	}

}
Determinant::Determinant(Matrix& mat) :Determinant(mat.data, mat.col, mat.row) {
}
number_complex Determinant::getValue() {//获取行列式的值
	return number_complex();
}
monomial<Determinant> Determinant::deploy(int x, int y) {//展开
	return monomial<Determinant>();
}