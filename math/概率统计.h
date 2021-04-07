#include<vector>

template <class T> T Sigma(std::vector<T> &arr){//求累加和	∑
	T s=0;
	for (auto i = arr.begin(); i != arr.end(); i++){
		s += *i;
	}
	return s;
}
template<class T> double expectation(std::vector<T>& arr){//求期望
	double s = Sigma(arr);
	return s / arr.size();
}
template<class T> double variance_unbiased(std::vector<T> &arr){//无偏估计，分母取n-1 D(x) 方差
	double s = 0;
	double e = expectation(arr);
	for (auto i = arr.begin(); i != arr.end(); i++){
		s += pow(e-*i,2);
	}
	return s / (arr.size()-1);
}
template<class T> double variance(std::vector<T> &arr){//有偏估计
	
	double miu = expectation(arr);
	vector<double> c;
	for (auto i = arr.begin(); i != arr.end(); i++){
		double s = pow(miu - *i, 2);
		c.push_back(s);
	}
	return expectation(c);
}
template<class T> double standardDeviation(std::vector<T> &arr){
	return sqrt(variance(arr));
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    