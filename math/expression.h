#pragma once
#include"assemblage.h"
#include"tool.h"
class Expression_integral:public element{//��ĸ������ĸ
	element A; 
	element B;
};
class expression
{
	expression& A;//ǰ����
	expression& B;//�󲿷�
	char type;//���ӷ��ţ�������
public:
	expression();
	~expression();
};

