#pragma once
class number_real
{
	char* data;//�洢ÿλ��Ĭ����10���ƴ洢
	int dot;//С����λ��
	int len;//λ��
public:
	number_real();//0
	number_real(int);//doubleȡ14λ��Ч����,ʵ��15λ,ĩβ0���洢
	number_real(float&);//floatȡ6λ��Ч����,ʵ��7λ,ĩβ0���洢
	number_real(double&);//doubleȡ14λ��Ч����,ʵ��15λ,ĩβ0���洢
	number_real operator*(int);
	number_real operator*(number_real&);
	number_real operator+(number_real&);
	number_real operator-(number_real&);
	number_real operator/(number_real&);
	number_real& operator+=(number_real&);
	number_real& operator*=(int);
	~number_real();
};