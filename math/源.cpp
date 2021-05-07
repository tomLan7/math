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
int main(){

	//recvTest({ {3,1,2,3} ,{1,2,3} });
	Matrix<double> m({ { 1.,6.,3 }, { 123.,2,3 } });
	//Matrix<double> m(3);
	cout << m.toString() << endl;
	return 0;
}
