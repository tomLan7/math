#pragma once
#include<exception>
class VectorException :
    public std::exception
{
    using std::exception::exception;
};
//Œ¨∂»≤ª∆•≈‰
class DimensionNotMatch:public VectorException{
public:

    using VectorException::VectorException;
};