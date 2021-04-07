#pragma once
class number_real
{
	char* data;//存储每位，默认是10进制存储
	int dot;//小数点位置
	int len;//位数
public:
	number_real();//0
	number_real(int);//double取14位有效数字,实际15位,末尾0不存储
	number_real(float&);//float取6位有效数字,实际7位,末尾0不存储
	number_real(double&);//double取14位有效数字,实际15位,末尾0不存储
	number_real operator*(int);
	number_real operator*(number_real&);
	number_real operator+(number_real&);
	number_real operator-(number_real&);
	number_real operator/(number_real&);
	number_real& operator+=(number_real&);
	number_real& operator*=(int);
	~number_real();
};