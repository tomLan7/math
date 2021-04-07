#pragma once
#include"string"
#include<iostream>
#include<vector>
#define DEBUG 1  //�Ƿ��ڵ��ԣ�����ڵ��Եû������г�Ա���η���Ϊpublic
//�洢һ������Z�ı����� �ֽڵ�λ��Ӧ���ֵ�λ
class integer 
{
#if DEBUG
public:
#endif
	std::vector<unsigned char> data;
	//Ϊ1λ����,Ϊ0������0��Ϊ-1�����Ǹ���
	int Positive;
	void swap(integer&);
	//�������ѵ�һ���͵ڶ����ӵ��������ϣ�����ʵ���ԼӺ����
	static void InternalPlus(const std::vector<unsigned char>& data1, const std::vector<unsigned char>& data2,std::vector<unsigned char>& ndata);
	//�ѵ�һ����ȥ�ڶ���������ڵ������ϡ�����ʵ���Լ������:Ҫ�󣬶����������ҵ�һ�����ڵڶ�����
	static void InternalSub(const std::vector<unsigned char>& data1, const std::vector<unsigned char>& data2,std::vector<unsigned char>& ndata);
	//����һ��С��256����,�������һλ
	static void InternalMult(const std::vector<unsigned char>& data1, int less256,std::vector<unsigned char>& ndata);
	//ƫ�ƶ���,�������λ�����ֱ�Ӳ�0��������С����λ��ֱ������
	static void InternalMultExcur(const std::vector<unsigned char>& data1, int numb, std::vector<unsigned char>& ndata);
	//�Ƚ����������ĸ���,��һ���󷵻�1���ڶ����󷵻�-1��ͬ���󷵻�0
	static int InternalCompare(const std::vector<unsigned char>& data1,const std::vector<unsigned char>& data2);
	//һ�δ������������һ�������̺���������,�����ĸ��ĸ��Ͳ��ܴ�Ϊ��
	static void InternalDivision(const std::vector<unsigned char>& data1, const std::vector<unsigned char>& data2,std::vector<unsigned char>* merchant, std::vector<unsigned char>* remainder);
public:
	//�ײ��Ƕ�����λ����,����Ԥ�����,���԰�ȫ��Զ��int��long��ȫ
	integer();//0
	//integer(const std::string&);//ʮ�����ַ���ת��integer

	//���� ��������
	integer(const integer&);
	//����,�ƶ�����
	integer(integer&&);
	//��װlong long
	integer(long long);
	//ת����ʮ�����ַ���
	std::string toString(int radix= 10) const;
	//���
	integer plus(const integer&) const;
	//�ӵ�
	integer& Addition(integer&);
	//�жϴ�С
	bool greater_than(const integer&)const;
	//�жϴ�С
	bool less_than(const integer&)const;
	bool equals(const integer&)const;
	/*
	����ֵ
	*/
	integer absoluteValue()const;
	/*
	//�෴�� -��Ŀ����
	*/
	integer opposite()const;
	//��ֵ�����
	integer& operator=(const integer& t);
	//�ƶ���ֵ����
	integer& operator=(integer&& t);
	//����
	integer multiplication(const integer&);
	//�˷�
	integer operator*(const integer&);
	//�ӷ�
	integer operator+(const integer&);
	//����
	integer operator-(const integer&);
	//����
	integer operator/(const integer&);
	//ȡ��
	integer operator%(const integer&);
	bool operator>(const integer&);
	bool operator<(const integer&);
	bool operator==(const integer&);
	bool operator!=(const integer&);
	integer operator-();

	//�������������,���Բ���,this��������,�����������
	integer division(const integer&);
	//����������������
	integer remainder(const integer&);
	//bool operator!=(const integer&);
	//operator bool();
	//~integer();
	static const integer  zero;
	static integer getMaxPublicNumb(integer,integer);//�������������������������������͸����͸���֮�����ۣ������͸���û�й�����
	static integer getMinPublicNumb(integer, integer);//��С��������Ҳ������������֮������
};
std::ostream& operator<<(std::ostream&, const integer& i);

/*���ַ�����洢10���Ƶ����֣�Ȼ������Ӽ��˳����ڴ˷�װ�ɶ���


string multiplication(string& a, int b);//����λ����һ������,������ӦС��10����Ҫ��ת
string expand10(string& a, int t);//�˶��ٴ�10��ƫ�ƶ���λ,��߼Ӷ��ٸ�0,��Ҫ��ת
int compare(string& a, string& b);//�ȴ�С����һ���󷵻�1���ڶ����󷵻�-1,��ȷ���0,��Ҫ��ת
string addition(string&a,string& b);//�ӷ����ڲ���������Ҫ��ת

string operator+(string& a, string& b);//�ӷ��ӿڣ�������
string operator*(string& a, string& b);//�˷��ӿ� ����multiplication������expand10��addition
string operator/(string& Division, string& s);//�����ӿ�
string operator/(string& Division, string& s){//һ��һ�����Ե�ȥ�Դ𰸣��������ù�������������̣��������ܣ�
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

void reverseSelf(string& s);//�ô˷�����תstring��������㣬�����Ҫ��ת����
string reverse(string& s);//�ô˷�����תstring������һ���µ��ַ���
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
string reverse(string& s){//�ô˷�����תstring������һ���µ��ַ���
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
string multiplication(string& a, int b){//����λ����һ������,������ӦС��10
	string tem = a;

	int buff = 0;
	int rsize = a.size();//ԭ����
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
string expand10(string& a, int t){//�˶��ٴ�10��ƫ�ƶ���λ,��߼Ӷ��ٸ�0
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
int compare(string& a, string& b){//�ȴ�С����һ���󷵻�1���ڶ����󷵻�-1,��ȷ���0
	if (a.size() != b.size()){//������Ȳ���ȣ����ñ���
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