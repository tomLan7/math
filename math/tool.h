#pragma once
#include<vector>
#include"integer.hpp"

//ͨ��ģ��
class tool
{
public:
	tool();
	~tool();
}; 
class mapping{//ӳ��,����һ��������һ��
	
};
class limitations :mapping{//һ����������,�������������true����false��true�Ļ�����ͨ��,�����mapping
	std::vector<limitations> tree;//���������п���������������������Ҫ�������������������ܷ���true
	bool (*user)(...);//һ������ָ��,��Ҫ����
	bool tryUser(...);//��Ҫ���㱾������������������������
};
template <class T>
class Vec2{//��ά���ݵĳ�����,������ͬ�����Ƕ�ά,�ݲ�������úʹ������壬���ɶ��Ƕ�������
	std::vector<T> data;
public:
	Vec2(const T& a, const T& b){
		data.push_back(a);
		data.push_back(b);
	}
	T& first(){
		return data[0];
	}
	T& second(){
		return data[1];
	}
};
template <class T>
class memoryManager{//�ڴ������
public:
	static bool equals(T& a, T& b){//�Ƚ�������ͬ���͵Ķ����Ƿ�����ȫ��ͬ
		int len = sizeof(a);
		char* p1 = (char*)(&a);
		char* p2 = (char*)(&b);
		while (len--){
			if (*p1++ != *p2++){
				return false;
			}
		}
		return true;
	}
	
};