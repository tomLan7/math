#pragma once
class Determinant {//行列式
	int order;//阶数
	number_complex* data;//本质
	int numb;//当前元素数,先行后列的添加,方便创建对象,
public:
	bool addElement(number_complex&);//添加一个元素，如果有未定义的元素的话,就会被填充，填充顺序是从上到下从左到右
	Determinant(number_complex*, int row, int col);
	Determinant(Matrix&);
	number_complex getValue();//获取行列式的值，如果行列式过多,则考虑先展开再计算
	monomial<Determinant> deploy(int x, int y);
};