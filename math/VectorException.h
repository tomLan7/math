#pragma once
#include<exception>
class VectorException :
    public std::exception
{
    using std::exception::exception;
};
//ά�Ȳ�ƥ��
class DimensionNotMatch:public VectorException{
public:

    using VectorException::VectorException;
};