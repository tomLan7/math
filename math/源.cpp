#include"Matrix.h"
#include<iostream>
using namespace std;
void recvTest(std::initializer_list<std::initializer_list<int>> list) {
	for (auto i:list) {
		for (auto j : i) {
			cout << j << "\t";
		}
		cout << endl;
	}
}
void testVectorAlg() {
	//实现零元
	double c = 2,c2=3;
	ColumnVector<double> x{ 2.,3. },y{ 1.,5. };
	bool b1 = c * c2 * x == c * (c2 * x);
	bool b2 = 1. * x == x;
	bool b3 = (x + y) == (y + x);
	bool b4 = c * (x + y) == c * x + c * y;
	bool b5 = (c + c2) * x == c * x + c2 * x;
	cout << b1 << "和" << b2 << "和" << b3 << "和" << b4 << "和" << b5   << endl;
}
int main(){
	testVectorAlg();
	return 0;
}
