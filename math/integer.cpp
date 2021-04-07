#include"integer.hpp"
#include<algorithm>
using namespace std;
const integer  integer::zero=0;
void integer::InternalPlus(const vector<unsigned char>& data1, const vector<unsigned char>& data2, vector<unsigned char>& ndata){
	int data1Size=data1.size();
	int data2Size = data2.size();
	ndata.resize(std::max(data1Size, data2Size) + 1);//�������������õĴ�С
	int buff = 0;//��������unsigned�ĺͣ���ȡ�������ֵ��data��Ȼ�����256��ʣ�µľ��ǽ�λ��Ϣ������н�λ��Ϣ���´��Զ���λ
	int len = 0;//��0λ��ʼ��
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

	ndata.resize(data1.size());//�������������õĴ�С
	
	bool borrow = false;//���Ϊtrue������ǰ����һλ����ǰ����Ҫ��ȥ
	int buff = 0;//��������unsigned�Ĳ������������ʹ�ǰһλ��1���ñ�Ǽ���
	int len = 0;//��0λ��ʼ��
	int Significant = 0;//��Чλ���Ӹ�λ��ʼ��һ����Ϊ0��λ
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
	int buff=0;//����洢����
	int data1Size = data1.size();//��ñ������Ĵ�С
	ndata.resize(data1Size + 1);//�Ƚ���С��Ϊ���ʴ�С
	for (int i = 0; i < data1Size;i++){//����һ�鱻����
		buff+=data1[i] * less256;
		ndata[i] = buff % 256;
		buff /= 256;
	}
	if (buff>0){//����ʣ�࣬������λ
		ndata[data1Size] = buff;
	}
	else{//���λû�У���������ȥ
		ndata.resize(data1Size);
	}

}
void integer::InternalMultExcur(const std::vector<unsigned char>& data1, int numb, std::vector<unsigned char>& ndata){
	if (numb==0){
		ndata = data1;
	}
	if (numb>0){//����10^numb�����Ӻ���ǰ����
		int data1Size = data1.size();
		ndata.resize(data1Size + numb);
		for (int i = data1Size - 1; i >= 0; i--){
			ndata[i + numb] = data1[i];
		} 
		for (int i = 0; i < numb;i++){
			ndata[i] = 0;
		}
	}
	else if (numb < 0){//��С10^numb������ǰ�����������
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
		for (int i = data1.size() - 1; i >= 0; i--){//�����һλ��ʼ�Ƚ�
			if (data1[i]>data2[i]){
				result = 1;
				break;
			}
			if (data1[i]<data2[i]){
				result = -1;
				break;
			}
			if (i == 0){//��ȣ��жϵ�i==0ʱҲû�ֳ�ʤ������ʱ����false
				result = 0;
			}
		}
	}
	return result;
}
void integer::InternalDivision(const std::vector<unsigned char>& data1, const std::vector<unsigned char>& data2, std::vector<unsigned char>* merchant, std::vector<unsigned char>* remainder){
	if (merchant){//�û���Ҫ�� 
		merchant->clear();
	}
	if (remainder){//�û���Ҫ���������������
		remainder->clear();
	}
	int psize = data2.size();//������λ��
	auto buff = data1;//������ʱ�ı��������棬������һ��һ���ȥ�������������ݣ�ʣ�µľ�������
	std::vector<unsigned char> cs;//������ʱ�ĳ������棬�᳢�Զ��룬����ķ���������
	int numb = buff.size() - cs.size();//��ǰ�ó������λ��������Ϊ���ó����ͱ�����������ƫ�Ƶ�λ����������������
	while (numb >= 0){//��ͷһֱѭ�������һλ
		InternalMultExcur(data2, numb, cs);//�Ƚ�����λ�����뵽buff������֮����������λ������Ϊnumb,��ʼ����������Ϊ1
		int i = 1;
		for (; i < 256; i++){//������255,��ʲôʱ�����������ȡ�������ڵ���������֮������������iΪ256ʱ��Ϊ���λλ��1λ
			int rtem = InternalCompare(cs, buff);//�Ƚϣ����С�ھͼ���i++��������ھ���ֹ��������ھͼ�һ����ֹ
			if (rtem == -1){//�ȱ���������С
				InternalMultExcur(data2, numb, cs);
				InternalMult(cs, i + 1, cs);//����һ��
			}
			else if (rtem == 1){//���ڱ���������
				i = i - 1;
				break;
			}
			else {//ǡ�����
				break;
			}
		}
		if (i != 0){//�ۼ���,�����0˵����λ������ֻ�������ٿ�
			InternalMult(data2, i, cs);//��øո�С�ڱ���������ĳ������飬���ӳ�ʼ��
			InternalMultExcur(cs, numb, cs);//λ�Ƴ�ʼ��
			InternalSub(buff, cs, buff);//�����������ȥ��������
			if (merchant){//�û���Ҫ�̣��ʹ�������̵Ľ��
				vector<unsigned char> temp;
				temp.push_back(i);
				InternalMultExcur(temp, numb, temp);
				InternalPlus(temp, *merchant, *merchant);
			}
		}
		numb--;
	}
	if (remainder){//�û���Ҫ��
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
	if (radix <= 0){//256���ư�ÿλ��10���Ʊ�ʾ��ÿλ֮���ÿո��ʾ��
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
	if (radix > 1 && radix <= 62){//С��36���ƶ����Բ������ַ��������ּ���ĸ�ı�ʾ��
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
	}//���������֧��10+26+26������ʾ��62���ƣ�
	else
	if (radix == 1){//1���ƣ��ر���ϵļ��������м�������ʾ����һ
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
				strrev((char*)(bout.c_str()));//�ַ�����ת�㷨
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

		if (Positive == 1){//������������
			if (p.Positive == 1){//���������ģ�������
				integer tem;
				InternalPlus(data,p.data,tem.data);
				tem.Positive=1;
				return tem;
			}
			else if(p.Positive==-1){//���ļӸ���
				integer tem;
				if (this->greater_than(p.opposite())){//�Ͷ�Ӧ���ֵ��෴���Ƚϣ������ʹﵽ�����������Ƚϵ�Ч����,��С�ڵĻ�������������͵�����
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
			if (p.Positive == 1){//���������ģ�������
				return p.plus(*this);
			}
			else{//���ļӸ���,ԭ���ǵ����������㷨����Ҫ�õ�������ʱinteger�����Ż��ռ�
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
		if (Positive == 1){//������������
			if (p.Positive == 1){//���������ģ�������
				InternalPlus(data,p.data,data);
				return *this;
			}
			else if (p.Positive == -1){//���ļӸ���
				if (this->greater_than(p.opposite())){//�Ͷ�Ӧ���ֵ��෴���Ƚϣ������ʹﵽ�����������Ƚϵ�Ч����,��С�ڵĻ�������������͵�����
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
		if (Positive == -1){//�������Ǹ���
			if (p.Positive == 1){//����������
				if (p.greater_than(opposite())){//�ﵽ����������
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
			else if (Positive == -1){//���Ӹ�
				InternalPlus(data,p.data,data);
				return *this;
			}
		}
	}
	bool integer::greater_than(const integer& p)const{
		
		if (Positive-p.Positive>0){//����λ�Ȳ����ķ���λ�ߣ��϶�����
			return true;
		}
		if (Positive - p.Positive<0){//����λ�Ȳ����ķ���λ�ͣ��϶�С��
			return false;
		}
		const vector<unsigned char>& data1 = this->data;//�������ã�����֮��������
		const vector<unsigned char>& data2 = p.data;//�������ã�����֮��������
		int result;//������������ʱ��������˭��������߶��Ǹ��ŵĻ�����Ҫȡ��
		result = InternalCompare(data1, data2);
		if (this->Positive<0&&p.Positive<0){//������������Ǹ��ģ�֮ǰ���ж�Ҫȡ��
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
		for (int i = 0; i < p.data.size();i++){//����p���ӵ�λһֱ���˷�
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
		if (this==&p){//һ������Ļ�һ�����
			return true;
		}
		if (p.Positive != Positive){
			return 0;
		}else
		if (Positive == 0){//���߶�Ϊ0
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
		�����������飬��������������
		�����������߼�0����úͱ���������һ��������1����2����3����4����ʲôʱ����ڱ��������飬��ȡi-1Ȼ���ñ����������ȥ�������飬
	*/
	integer integer::division(const integer& p){
		if (p.Positive == 0){
			throw "����Ϊ0����";
		}
		if (Positive==0){
			return 0;
		}
		integer result;
		InternalDivision(data, p.data, &result.data, 0); 
		if (result.data.size() == 0){//������������������ڱ�����ʱ���Ϊ0
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
			throw "����Ϊ0����";
		}
		if (Positive == 0){
			return 0;
		}
		integer result;
		InternalDivision(data,p.data,0,&result.data);
		if (result.data.size()==0){//������������������ʱ������Ϊ0
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
			a.swap(b);//��֤a����b
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
	//integer integer::operator%(const integer&);//ȡ��
	//bool integer::operator>(const integer&);//�ж�����int��С
	//bool integer::operator<(const integer&);//�Ƿ�С��
	//bool integer::operator!=(const integer&);
	//integer integer::operator/(const integer&);//�����������з����
	//operator integer::bool();
	//integer::~integer();
	//static const integer  integer::zero;
	//static integer integer::getMaxPublicNumb(integer, integer);//�������������������������������͸����͸���֮�����ۣ������͸���û�й�����
	std::ostream& ::operator<<(std::ostream& c, const integer& i){
		c << i.toString();
		return c;
	}