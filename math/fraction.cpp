#include"fraction.h"

std::ostream& operator<<(std::ostream& c, fraction& i){
	c << "("<<i.getMolecule() << "/" << i.getDenominator()<<")";
	return c;
}
void fraction::setAutoSimple(const bool a){
	autoSimple = a;
}
bool fraction::getAutoSimple(){
	return autoSimple;
}
fraction::fraction() :autoSimple(true), data(integer(), integer(1)){
}
fraction::fraction(long l) : autoSimple(true), data(integer(l), integer(1)){
}
fraction::fraction(double d) : autoSimple(true), data(integer(1), integer(1)){
	
}
fraction::fraction(const integer& i):data(i, integer(1)){
}
fraction::fraction(const integer& a,const integer& b) : data(a, b){
	
}
fraction& fraction::Simplification(){
	integer tem = integer::getMaxPublicNumb(data.first(), data.second());
	data.first() = data.first()/tem;
	data.second() =data.second()/tem;
	return *this;
}
integer& fraction::getDenominator(){
	return data.second();
}
integer& fraction::getMolecule(){
	return data.first();
}
integer fraction::getCeil(){
	if (data.first() % data.second() == integer::zero){
		return data.first() / data.second();
	}
	else{
		return data.first() / data.second()+integer(1);
	}
	
}
integer fraction::getfloor(){
	return data.first() / data.second();
}
fraction::~fraction(){

}
fraction fraction::operator*(fraction& j){
	fraction result= fraction(data.first()*j.data.first(), data.second()*j.data.second());
	if (autoSimple){
		result.Simplification();
	}
	return result;
}
fraction fraction::operator+(fraction& j){
	integer c=integer::getMinPublicNumb(data.second(),j.data.second());
	fraction result=fraction(data.first()*c/data.second() +j.data.first()*c/j.data.second(), c);
	if (autoSimple){
		result.Simplification();
	}
	return result;
}