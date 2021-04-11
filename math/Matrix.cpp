#include "Matrix.h"


Matrix::Matrix(number_complex* arr, int r, int c)
{
	if (r <= 0 || c <= 0){//生成空矩阵
		data = 0;
		row = 0;
		col = 0;
		return;
	}
	data = new number_complex[r*c];
	row = r;
	col = c;
	for (int i = r*c - 1; i >= 0; i--){
		data[i] = arr[i];
	}
}
Matrix::Matrix(int level, number_complex& value){//阶数,可以设置主对角线初始值
	if (level<= 0){//生成空矩阵
		data = 0;
		row = 0;
		col = 0;
		return;
	}
	data = new number_complex[level*level];
	row = level;
	col = level;
	for (int i = 0; i < row; i++){
				data[i*col+i]=value;
	}
}
Matrix::Matrix(){
	data = 0;
	row = 0;
	col = 0;
}
Matrix::~Matrix()
{
	delete[] data;
}
Matrix Matrix::getAdjoint(){//获得伴随矩阵
	if (row*col == 0){
		return Matrix();
	}
	auto p=new number_complex[row*col];
	for (int i = 0; i < row; i++){
		for (int i2 = 0; i2 < col; i2++){
			p [i*row+i2]=getCofactor(i, i2).getDeterminantValue()*((i+i2)%2?-1:1);//余子式的行列式乘以位置代数
		}
	}
	Matrix adj(p,row,col);
	delete[] p;
	return adj;
}
Matrix Matrix::getInverse(){//获得逆
	if (row*col == 0){
		return Matrix();
	}
	return getAdjoint() / getDeterminantValue();
}
number_complex Matrix::getDeterminantValue(){//获得行列式的值
	return getDeterminant().getValue();
}
Determinant Matrix::getDeterminant(){//获得行列式
	return Determinant(data,row,col);
}
Matrix Matrix::getCofactor(int r, int c){//获得指定元素的余子式
	if (row*col == 0){
		return Matrix();
	}

	auto p = new number_complex[(row-1)*(col-1)];
	if (row*col == 0){
		delete[] p;
		return Matrix();
	}
	int dex = 0;
	for (int i = 0; i < row;i++){
		for (int i2 = 0; i2 < col; i2++){
			if (i == c || i2 == r){
				continue;
			}
			p[dex] = data[i*row+i2];
		}
	}
	Matrix cof(p,row-1,col-1);
	delete[] p;
	return cof;
}
Matrix operator*(int a, Matrix b){
	return b*a;
}
Matrix Matrix::operator*(int coefficient){
	auto p = new number_complex[row*col];
	for (int i = row*col - 1; i >= 0; i--){
		p[i] *= coefficient;
	}
	Matrix result = Matrix(p,row,col);
	delete[] p;
	return result;
}
Matrix Matrix::operator+(Matrix& b){
	auto p = new number_complex[row*col];
	for (int i = row*col - 1; i >= 0; i--){
		p[i] = data[i]+b.data[i];
	}
	Matrix result = Matrix(p, row, col);
	delete[] p;
	return result;
}
Matrix Matrix::operator*(Matrix& d){
	if (d.row != col){//行数和列数不匹配
		throw 1;
	}
	auto p = new number_complex[row*d.col];
	for (int i = 0; i < row; i++){
		for (int i2 = 0; i2 < d.col; i2++){
			number_complex sum;
			for (int is = 0; is < col; is++){
				sum += d.data[is*d.row + i2] * data[i*row + is];
			}
			p[i*row + i2] = sum;
		}
	}
	Matrix result = Matrix(p, row, d.col);
	delete[] p;
	return result;
}
int Matrix::getRank(){//返回矩阵的秩，算法:通过一些初等变换改变为阶梯型矩阵，然后计算矩阵的秩
	return 0;
}
int Matrix::getRow(){//返回行数
	return row;
}
int Matrix::getCol(){//返回列数
	return col;
}
Matrix Matrix::operator / (number_complex& b){
	auto p = new number_complex[row*col];
	for (int i = row*col - 1; i >= 0; i--){
		p[i] = data[i]/b;
	}
	Matrix result = Matrix(p, row, col);
	delete[] p;
	return result;
}


