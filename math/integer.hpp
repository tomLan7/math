#pragma once
#include"string"
#include<iostream>
#include<vector>
#define DEBUG 1  //是否在调试，如果在调试得话，所有成员修饰符均为public
//存储一个整数Z的变量， 字节低位对应数字低位
class integer 
{
#if DEBUG
public:
#endif
	std::vector<unsigned char> data;
	//为1位正数,为0代表是0，为-1代表是负数
	int Positive;
	void swap(integer&);
	//方法，把第一个和第二个加到第三个上，可以实现自加和相加
	static void InternalPlus(const std::vector<unsigned char>& data1, const std::vector<unsigned char>& data2,std::vector<unsigned char>& ndata);
	//把第一个减去第二个，结果在第三个上。可以实现自减和相减:要求，都是正数，且第一个大于第二个，
	static void InternalSub(const std::vector<unsigned char>& data1, const std::vector<unsigned char>& data2,std::vector<unsigned char>& ndata);
	//乘以一个小于256的数,最多增加一位
	static void InternalMult(const std::vector<unsigned char>& data1, int less256,std::vector<unsigned char>& ndata);
	//偏移多少,扩大多少位，后边直接补0，或是缩小多少位，直接左移
	static void InternalMultExcur(const std::vector<unsigned char>& data1, int numb, std::vector<unsigned char>& ndata);
	//比较两个数组哪个大,第一个大返回1，第二个大返回-1，同样大返回0
	static int InternalCompare(const std::vector<unsigned char>& data1,const std::vector<unsigned char>& data2);
	//一次带余除法，生成一个整数商和整数余数,想获得哪个哪个就不能传为空
	static void InternalDivision(const std::vector<unsigned char>& data1, const std::vector<unsigned char>& data2,std::vector<unsigned char>* merchant, std::vector<unsigned char>* remainder);
public:
	//底层是二进制位运算,可以预防溢出,绝对安全，远比int和long安全
	integer();//0
	//integer(const std::string&);//十进制字符串转化integer

	//重载 拷贝构造
	integer(const integer&);
	//重载,移动构造
	integer(integer&&);
	//封装long long
	integer(long long);
	//转换成十进制字符串
	std::string toString(int radix= 10) const;
	//相加
	integer plus(const integer&) const;
	//加得
	integer& Addition(integer&);
	//判断大小
	bool greater_than(const integer&)const;
	//判断大小
	bool less_than(const integer&)const;
	bool equals(const integer&)const;
	/*
	绝对值
	*/
	integer absoluteValue()const;
	/*
	//相反数 -单目运算
	*/
	integer opposite()const;
	//赋值运算符
	integer& operator=(const integer& t);
	//移动赋值语义
	integer& operator=(integer&& t);
	//数乘
	integer multiplication(const integer&);
	//乘法
	integer operator*(const integer&);
	//加法
	integer operator+(const integer&);
	//减法
	integer operator-(const integer&);
	//除法
	integer operator/(const integer&);
	//取余
	integer operator%(const integer&);
	bool operator>(const integer&);
	bool operator<(const integer&);
	bool operator==(const integer&);
	bool operator!=(const integer&);
	integer operator-();

	//除法，带余除法,除以操作,this代表被除数,参数代表除数
	integer division(const integer&);
	//计算带余除法的余数
	integer remainder(const integer&);
	//bool operator!=(const integer&);
	//operator bool();
	//~integer();
	static const integer  zero;
	static integer getMaxPublicNumb(integer,integer);//最大公因数，最大公因数是在正数和整数和负数和负数之间讨论，正数和负数没有公因数
	static integer getMinPublicNumb(integer, integer);//最小共倍数，也是正数和整数之间讨论
};
std::ostream& operator<<(std::ostream&, const integer& i);

/*用字符数组存储10进制的数字，然后运算加减乘除，在此封装成对象


string multiplication(string& a, int b);//所有位乘以一个数字,该数字应小于10，需要调转
string expand10(string& a, int t);//乘多少次10，偏移多少位,后边加多少个0,需要调转
int compare(string& a, string& b);//比大小，第一个大返回1，第二个大返回-1,相等返回0,需要调转
string addition(string&a,string& b);//加法，内部方法，需要调转

string operator+(string& a, string& b);//加法接口，不依赖
string operator*(string& a, string& b);//乘法接口 依赖multiplication方法和expand10和addition
string operator/(string& Division, string& s);//除法接口
string operator/(string& Division, string& s){//一个一个尝试的去试答案，不建议用过大的数，返回商（余数不管）
if (Division.size() < s.size()){
return "0";
}
string tem(Division.begin(), Division.begin()+s.size());
for (int i = s.size()-1;i<Division.size(); i++){
tem=tem*string("10")+Division[i];
for (int i2 = 1; i2 < 10;i2++){

}
}
}

void reverseSelf(string& s);//用此方法倒转string，方便计算，计算后还要倒转回来
string reverse(string& s);//用此方法倒转string，产生一个新的字符串
int main(){
string a = "55";
string b = "289";
//reverseSelf(a);
//reverseSelf(b);
//a=a* b;
cout << a*b << endl;
return 1;
}

void reverseSelf(string& s){
	for (int i = 0; i < s.size() / 2; i++){
		swap(s[i], s[s.size() - 1 - i]);
	}
}
string reverse(string& s){//用此方法倒转string，产生一个新的字符串
	string a = s;
	for (int i = 0; i < s.size() / 2; i++){
		swap(a[i], a[s.size() - 1 - i]);
	}
	return a;
}

string addition(string& a, string& b){
	int buff = 0;
	int mlen = max(a.size(), b.size());
	string r;
	r.resize(mlen + 1);
	for (int i = 0; i < mlen; i++){
		if (i < a.size()){
			buff += a[i] - '0';
		}
		if (i < b.size()){
			buff += b[i] - '0';
		}
		r[i] = buff % 10 + '0';
		buff /= 10;
	}
	if (buff == 0){
		r.resize(mlen);
	}
	else{
		r[mlen] = (char)(buff + '0');
	}
	return r;
}
string operator+(string& a, string& b){
	reverseSelf(a);
	reverseSelf(b);
	string tem = addition(a, b);
	reverseSelf(a);
	reverseSelf(b);
	reverseSelf(tem);
	return tem;
}
string multiplication(string& a, int b){//所有位乘以一个数字,该数字应小于10
	string tem = a;

	int buff = 0;
	int rsize = a.size();//原长度
	tem.resize(rsize + 1);
	for (int i = 0; i < rsize; i++){
		buff += (a[i] - '0') * b;
		tem[i] = (char)(buff % 10 + '0');
		buff /= 10;
	}
	if (buff == 0){
		tem.resize(rsize);
	}
	else{
		tem[rsize] = buff + '0';
	}
	return tem;
}
string expand10(string& a, int t){//乘多少次10，偏移多少位,后边加多少个0
	string tem = a;
	int rs = a.size() - 1;
	tem.resize(a.size() + t);
	int i = tem.size() - 1;
	for (; rs >= 0; i--){
		tem[i] = a[rs--];
	}
	for (; i >= 0; i--){
		tem[i] = '0';
	}
	return tem;
}
string operator*(string& a, string& b){
	reverseSelf(a);
	reverseSelf(b);
	int msize = max(a.size(), b.size());
	string tem;
	for (int i = 0; i < a.size(); i++){
		tem = addition(tem, expand10((multiplication(b, (a[i] - '0'))), i));
	}
	reverseSelf(tem);
	reverseSelf(a);
	reverseSelf(b);
	return tem;
}
int compare(string& a, string& b){//比大小，第一个大返回1，第二个大返回-1,相等返回0
	if (a.size() != b.size()){//如果长度不相等，不用比了
		return a.size()>b.size() ? 1 : -1;
	}
	for (int i = a.size() - 1; i >= 0; i--){
		if (a[i] != b[i]){
			return a[i] > b[i] ? 1 : -1;
		}
	}
	return 0;
}


*/