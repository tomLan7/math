#pragma once
#include"assemblage.h"
#include"tool.h"
class Expression_integral:public element{//分母不含字母
	element A; 
	element B;
};
class expression
{
	expression& A;//前部分
	expression& B;//后部分
	char type;//连接符号（函数）
public:
	expression();
	~expression();
};

