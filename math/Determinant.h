#pragma once
#include<vector>
template<typename T>class Martix;
template<typename T>
class Determinant {//n������ʽ������
	int order;//����
	std::vector<T> data;//����Ԫ��
public:
	bool addElement(T&& obj);//���һ��Ԫ�أ������δ�����Ԫ�صĻ�,�ͻᱻ��䣬���˳���Ǵӵ�һ���ϵ���.
	Determinant(const T*,int n_order);
	//Determinant(Matrix<T>& mtx);

	//��ȡ����ʽ��ֵ���������ʽ����,������չ���ټ���
	T getValue();
	T get(int x, int y);
};