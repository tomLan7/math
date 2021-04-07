#include"integer.hpp"
#include<algorithm>
using namespace std;
const integer  integer::zero=0;
void integer::InternalPlus(const vector<unsigned char>& data1, const vector<unsigned char>& data2, vector<unsigned char>& ndata){
	int data1Size=data1.size();
	int data2Size = data2.size();
	ndata.resize(std::max(data1Size, data2Size) + 1);//数组扩容至可用的大小
	int buff = 0;//存着两个unsigned的和，把取余的数赋值给data，然后除以256，剩下的就是进位信息，如果有进位信息则下次自动进位
	int len = 0;//从0位开始加
	while (data1Size>len || data2Size>len){
		if (data1Size > len){
			buff += data1[len];
		}
		if (data2Size > len){
			buff += data2[len];
		}
		ndata[len] = buff % 256;
		buff /= 256;
		len++;
	}
	if (buff>0){
		ndata[len] = buff;
		len++;
	}
	ndata.resize(len);
}
void integer::InternalSub(const vector<unsigned char>& data1, const vector<unsigned char>& data2, vector<unsigned char>& ndata){
	int data1Size = data1.size();
	int data2Size = data2.size();

	ndata.resize(data1.size());//数组扩容至可用的大小
	
	bool borrow = false;//如果为true代表向前借了一位，到前边需要减去
	int buff = 0;//存着两个unsigned的差，如果不够减，就从前一位借1，用标记记下
	int len = 0;//从0位开始加
	int Significant = 0;//有效位，从高位开始第一个不为0的位
	while (data1Size>len || data2Size>len){
		if (data1Size > len){
			buff += data1[len];
		}
		if (data2Size > len){
			buff -= data2[len];
		}
		if (borrow){
			buff--;
			borrow = false;
		}
		if (buff<0){
			buff += 256;
			borrow = true;
		}
		if (buff != 0){
			Significant = len + 1;
		}
		ndata[len] = buff % 256;
		buff /= 256;
		len++;

	}

	ndata.resize(Significant);
}
void integer::InternalMult(const std::vector<unsigned char>& data1, int less256, std::vector<unsigned char>& ndata){
	int buff=0;//负责存储缓存
	int data1Size = data1.size();//获得被乘数的大小
	ndata.resize(data1Size + 1);//先将大小置为合适大小
	for (int i = 0; i < data1Size;i++){//遍历一遍被乘数
		buff+=data1[i] * less256;
		ndata[i] = buff % 256;
		buff /= 256;
	}
	if (buff>0){//还有剩余，放在新位
		ndata[data1Size] = buff;
	}
	else{//最高位没有，所以缩回去
		ndata.resize(data1Size);
	}

}
void integer::InternalMultExcur(const std::vector<unsigned char>& data1, int numb, std::vector<unsigned char>& ndata){
	if (numb==0){
		ndata = data1;
	}
	if (numb>0){//扩大10^numb倍，从后往前遍历
		int data1Size = data1.size();
		ndata.resize(data1Size + numb);
		for (int i = data1Size - 1; i >= 0; i--){
			ndata[i + numb] = data1[i];
		} 
		for (int i = 0; i < numb;i++){
			ndata[i] = 0;
		}
	}
	else if (numb < 0){//缩小10^numb倍，从前往后遍历复制
		int data1Size = data1.size();
		
		for (int i = -numb; i < data1.size(); i++){
			ndata[i+numb] = data1[i];
		}
		for (int i = 0; i < numb; i++){
			ndata[i] = 0;
		}
		ndata.resize(data1Size + numb);
	}
	
}
int integer::InternalCompare(const std::vector<unsigned char>& data1, const  std::vector<unsigned char>& data2){
	int result;
	if (data1.size() > data2.size()){
		result = 1;
	}
	else if (data1.size() < data2.size()){
		result = -1;
	}
	else{
		for (int i = data1.size() - 1; i >= 0; i--){//从最后一位开始比较
			if (data1[i]>data2[i]){
				result = 1;
				break;
			}
			if (data1[i]<data2[i]){
				result = -1;
				break;
			}
			if (i == 0){//相等，判断到i==0时也没分出胜负，这时返回false
				result = 0;
			}
		}
	}
	return result;
}
void integer::InternalDivision(const std::vector<unsigned char>& data1, const std::vector<unsigned char>& data2, std::vector<unsigned char>* merchant, std::vector<unsigned char>* remainder){
	if (merchant){//用户需要商 
		merchant->clear();
	}
	if (remainder){//用户需要余数，清除答案数组
		remainder->clear();
	}
	int psize = data2.size();//除数的位数
	auto buff = data1;//存着临时的被除数缓存，除法会一点一点扣去这个缓存里的内容，剩下的就是余数
	std::vector<unsigned char> cs;//存着临时的除数缓存，会尝试对齐，对齐的方法就是商
	int numb = buff.size() - cs.size();//当前得出结果的位数，就是为了让除数和被除数对齐所偏移的位数，除数扩大因子
	while (numb >= 0){//从头一直循环到最后一位
		InternalMultExcur(data2, numb, cs);//先将除数位数对齐到buff，方便之后做减法，位移因子为numb,初始化倍数因子为1
		int i = 1;
		for (; i < 256; i++){//遍历到255,看什么时候会大于这个，取即将大于的数，用来之后做减法，当i为256时即为向高位位移1位
			int rtem = InternalCompare(cs, buff);//比较，如果小于就继续i++，如果等于就终止，如果大于就减一并终止
			if (rtem == -1){//比被除数数组小
				InternalMultExcur(data2, numb, cs);
				InternalMult(cs, i + 1, cs);//扩大一倍
			}
			else if (rtem == 1){//大于被除数数组
				i = i - 1;
				break;
			}
			else {//恰好相等
				break;
			}
		}
		if (i != 0){//累加商,如果得0说明这位不够大，只能往后再看
			InternalMult(data2, i, cs);//获得刚刚小于被除数数组的除数数组，因子初始化
			InternalMultExcur(cs, numb, cs);//位移初始化
			InternalSub(buff, cs, buff);//被除数数组减去除数数组
			if (merchant){//用户需要商，就存着这个商的结果
				vector<unsigned char> temp;
				temp.push_back(i);
				InternalMultExcur(temp, numb, temp);
				InternalPlus(temp, *merchant, *merchant);
			}
		}
		numb--;
	}
	if (remainder){//用户需要商
		remainder->swap(buff);
	}
}
void integer::swap(integer& p){
	p.data.swap(this->data);
	std::swap(p.Positive, this->Positive);
}
integer::integer() :Positive(0){

}
integer::integer(const integer& p){
	Positive = p.Positive;
	data = p.data;
}
integer::integer(integer&& p){
	Positive = p.Positive;
	data.swap(p.data);
}
integer::integer(long long l){
	if (l < 0){
		Positive = -1;
	}
	else if (l>0){
		Positive = 1;
	}
	else{
		Positive = 0;
	}
	l = std::abs(l);
	while (l>0)
	{
		data.push_back((unsigned char)(l % 256));
		l /= 256;
	}
}
integer& integer::operator = (const integer& t){
	data = t.data;
	Positive = t.Positive;
	return *this;
}
integer& integer::operator=(integer&& p){
	this->data.swap(p.data);
	this->Positive = p.Positive;
	return *this;
}
std::string integer::toString(int radix) const{
	if (radix <= 0){//256进制把每位用10进制表示，每位之间用空格表示，
		char *buff = new char[5];
		string str;
		str.push_back('[');
		if (Positive == -1){
			str.append(" -");
		}
		for (int i = data.size() - 1; i >= 0; i--){
			sprintf(buff, "%d", (int)data[i]);
			str.append(buff);
			if (i != 0){
				str.push_back(' ');
			}
		}
		str.push_back(']');
		delete buff;
		return str;
	}
	else
	if (radix > 1 && radix <= 62){//小于36进制都可以采用这种方法，数字加字母的表示法
		char chartable[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
			'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
			'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
			'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D',
			'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',
			'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
			'Y', 'Z' };
		string str;
		auto buff = *this;
		while (buff.Positive != 0){

			integer&& b = (buff % radix).absoluteValue();
			if (b.Positive != 0){
				str.push_back(chartable[b.data[0]]);
			}
			else{
				str.push_back('0');
			}
			buff = buff / radix;
		}
		if (Positive == -1){
			str.push_back('-');
		}
		for (int i = 0; i < str.size() / 2; i++){
			char c = str[i];
			str[i] = str[str.size() - i - 1];
			str[str.size() - i - 1] = c;
		}
		return str;
	}//本方法最多支持10+26+26进制显示（62进制）
	else
	if (radix == 1){//1进制，特别古老的计数法，有几个就显示几个一
		string str;
		if (Positive == -1){
			str.push_back('-');
		}
		for (auto i = data.begin(); i != data.end(); i++){
			for (int j = 0; j < *i; j++){
				str.push_back('1');
			}
		}
		return str;
	}
	else{
		string str;
		auto buff = *this;
		char cb[512];
		str.push_back(']');
		while (buff.Positive != 0){
			integer&& b = (buff % radix).absoluteValue();
			if (b.Positive != 0){
				string bout = b.toString();
				strrev((char*)(bout.c_str()));//字符串倒转算法
				str.append(bout);
			}
			else{
				str.push_back('0');
			}
			buff = buff / radix;
			if (buff.Positive != 0){
				str.push_back(' ');
			}
		}
		if (Positive == -1){
			str.append(" -");
		}
		str.push_back('[');
		strrev((char*)str.c_str());
		return str;
	}
}

	integer integer::plus(const integer& p) const{
		if (Positive == 0){
			return p;
		}
		if (p.Positive==0){
			return *this;
		}

		if (Positive == 1){//本对象是正的
			if (p.Positive == 1){//加数是正的，正常加
				integer tem;
				InternalPlus(data,p.data,tem.data);
				tem.Positive=1;
				return tem;
			}
			else if(p.Positive==-1){//正的加负的
				integer tem;
				if (this->greater_than(p.opposite())){//和对应数字的相反数比较，这样就达到正数和正数比较的效果了,不小于的话就正常，否则就调过来
					tem.Positive = 1;
					InternalSub(this->data,p.data,tem.data);
				}
				else{
					tem.Positive = -1;
					InternalSub(p.data, this->data, tem.data);
				}
				if (tem.data.size() == 0){
					tem.Positive = 0;
				}
				return tem;
			}
		}
		else{
			if (p.Positive == 1){//加数是正的，正常加
				return p.plus(*this);
			}
			else{//负的加负的,原理是调用正数的算法，需要用到两个临时integer，有优化空间
				integer tem1 = *this;
				integer tem2 = p;
				tem1.Positive = 1;
				tem2.Positive = 1;
				integer tem3 = tem1.plus(tem2);
				tem3.Positive = -1;
				return tem3;
			}
		}
	}
	integer& integer::Addition(integer& p){
		if (p.Positive == 0){
			return *this;
		}
		if (Positive == 0){
			this->operator=(p);
			return *this;
		}
		if (Positive == 1){//本对象是正的
			if (p.Positive == 1){//加数是正的，正常加
				InternalPlus(data,p.data,data);
				return *this;
			}
			else if (p.Positive == -1){//正的加负的
				if (this->greater_than(p.opposite())){//和对应数字的相反数比较，这样就达到正数和正数比较的效果了,不小于的话就正常，否则就调过来
					InternalSub(this->data, p.data, data);
					Positive = 1;
				}
				else{
					InternalSub(p.data, this->data, data);
					Positive = -1;
				}
				if (data.size() == 0){
					Positive = 0;
				}
				return *this;
			}
		}else
		if (Positive == -1){//本对象是负数
			if (p.Positive == 1){//负数加正的
				if (p.greater_than(opposite())){//达到正数比正数
					InternalSub(p.data, data, data);
					Positive = 1;
				}
				else{
					InternalSub(data, p.data, data);
					Positive = -1;
				}
				if (data.size() == 0){
					Positive = 0;
				}
				return *this;
			}
			else if (Positive == -1){//负加负
				InternalPlus(data,p.data,data);
				return *this;
			}
		}
	}
	bool integer::greater_than(const integer& p)const{
		
		if (Positive-p.Positive>0){//符号位比参数的符号位高，肯定大于
			return true;
		}
		if (Positive - p.Positive<0){//符号位比参数的符号位低，肯定小于
			return false;
		}
		const vector<unsigned char>& data1 = this->data;//保存引用，方便之后计算调用
		const vector<unsigned char>& data2 = p.data;//保存引用，方便之后计算调用
		int result;//当成两个正数时计算结果是谁大，如果两者都是负号的话，还要取反
		result = InternalCompare(data1, data2);
		if (this->Positive<0&&p.Positive<0){//如果两个数都是负的，之前的判断要取反
			result *= -1;
		}
		return result==1;
	}
	bool integer::less_than(const integer& t)const{
		return t.greater_than(*this);
	}
	
	integer integer::opposite()const{
		integer i = *this;
		i.Positive = -i.Positive;
		return i;
	}
	integer integer::absoluteValue()const{
		integer i = *this;
		if (i.Positive == -1){
			i.Positive = 1;
		}
		return i;
	}
	integer integer::multiplication(const integer& p){
		integer sum;
		integer tem;
		for (int i = 0; i < p.data.size();i++){//遍历p，从低位一直做乘法
			InternalMult(this->data, p.data[i], tem.data);
			InternalMultExcur(tem.data, i, tem.data);
			InternalPlus(sum.data,tem.data,sum.data);
		}
		if (p.Positive&&Positive){
			sum.Positive=(p.Positive == Positive) ? 1 : -1;
		}
		else{
			sum.Positive = 0;
		}
		return sum;
	}
	
	integer integer::operator*(const integer& p){
		return multiplication(p); 
	}
	integer integer::operator+(const integer& p){
		return plus(p);
	}
	integer integer::operator-(const integer& p){
		return plus(p.opposite());
	}
	integer integer::operator/(const integer& p){
		return division(p);
	}
	integer integer::operator%(const integer& p){
		return remainder(p);
	}
	bool integer::equals(const integer& p)const{
		if (this==&p){//一个对象的话一定相等
			return true;
		}
		if (p.Positive != Positive){
			return 0;
		}else
		if (Positive == 0){//两者都为0
			return 1;
		}
		return InternalCompare(this->data, p.data)==0;
	}
	bool integer::operator>(const integer& p){
		return greater_than(p);
	}
	bool integer::operator<(const integer& p){
		return less_than(p);
	}
	bool integer::operator==(const integer& p){
		return equals(p);
	}
	bool integer::operator!=(const integer& p){
		return !equals(p);
	}
	integer integer::operator-(){
		return opposite();
	}
	/*
		除数缓存数组，被除数缓存数组
		将除数数组后边加0，变得和被除数数组一样长，乘1，乘2，乘3，乘4，看什么时候大于被除数数组，就取i-1然后让被除数数组减去除数数组，
	*/
	integer integer::division(const integer& p){
		if (p.Positive == 0){
			throw "除数为0错误";
		}
		if (Positive==0){
			return 0;
		}
		integer result;
		InternalDivision(data, p.data, &result.data, 0); 
		if (result.data.size() == 0){//带余除法，当除数大于被除数时结果为0
			result.Positive = 0;
		}
		else
		if (Positive == p.Positive){
			result.Positive = 1;
		}
		else{
			result.Positive = -1;
		}
		return result;
	}
	
	integer integer::remainder(const integer& p){
		if (p.Positive == 0){
			throw "余数为0错误";
		}
		if (Positive == 0){
			return 0;
		}
		integer result;
		InternalDivision(data,p.data,0,&result.data);
		if (result.data.size()==0){//当除数整除被除数的时候余数为0
			result.Positive = 0;
		}else
		if (Positive ==-1){
			result.Positive = -1;
		}
		else{
			result.Positive = 1;
		}
		return result;
	}
	integer integer::getMaxPublicNumb(integer a, integer b){
		if (b > a){
			a.swap(b);//保证a大于b
		}
		integer c = a%b;
		while (c != 0){
			a = b;
			b = c;
			c = a%b;
		}
		return b;
	}
	integer integer::getMinPublicNumb(integer a, integer b){
		return a*b / getMaxPublicNumb(a,b);
	}
	//integer integer::operator%(const integer&);//取余
	//bool integer::operator>(const integer&);//判断两个int大小
	//bool integer::operator<(const integer&);//是否小于
	//bool integer::operator!=(const integer&);
	//integer integer::operator/(const integer&);//除法，不具有封闭性
	//operator integer::bool();
	//integer::~integer();
	//static const integer  integer::zero;
	//static integer integer::getMaxPublicNumb(integer, integer);//最大公因数，最大公因数是在正数和整数和负数和负数之间讨论，正数和负数没有公因数
	std::ostream& ::operator<<(std::ostream& c, const integer& i){
		c << i.toString();
		return c;
	}