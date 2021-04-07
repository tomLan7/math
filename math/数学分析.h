#include<iostream>
#include<vector>
#include <initializer_list>
std::vector<double> getRoot(double a, double b, double c){//求二次方根,(-b+-(b^2-4*a*c)^(0.5))/2*a
	std::vector<double> v;
	double dt = pow(b, 2) - (4 * a*c);
	if (dt < 0){
	}
	else if(dt==0){
		v.push_back( -b / (2 * a));
	}
	else{
		v.push_back((-b + pow(dt, 0.5)) / (2 * a));
		v.push_back((-b - pow(dt, 0.5)) / (2 * a));
	}
	return v;
}
double getSum(double x, std::initializer_list<double> l){//相当于 x^n*a1+x^(n-1)*a2+……+x^2*a(n-1)+x^1*an+x^0*a(n+1)
	int n = l.size();
	n--;
	double s = 0;
	for (auto i = l.begin(); i != l.end(); i++){
		s += pow(x, n--)**i;
	}
	return s;
};
