#pragma once
class Determinant {//����ʽ
	int order;//����
	number_complex* data;//����
	int numb;//��ǰԪ����,���к��е����,���㴴������,
public:
	bool addElement(number_complex&);//���һ��Ԫ�أ������δ�����Ԫ�صĻ�,�ͻᱻ��䣬���˳���Ǵ��ϵ��´�����
	Determinant(number_complex*, int row, int col);
	Determinant(Matrix&);
	number_complex getValue();//��ȡ����ʽ��ֵ���������ʽ����,������չ���ټ���
	monomial<Determinant> deploy(int x, int y);
};