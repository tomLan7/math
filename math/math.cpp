#include <string>
#include"����ͳ��.h"
#include"��ѧ����.h"
#include"integer.hpp"
//#include"fraction.h"
//#include"windows.h"
//#include<time.h>
//#include<functional>
//#include<math.h>
//#include<lanF.h>
//#pragma comment(lib,"lanF.lib")
#include<algorithm>
#include<vector>
#include<iostream>
#include"fraction.h"
#include<bitset>
using namespace std;
int main2(){
	fraction c(5, 8);
	fraction d(5, 5);
	cout << (c + d) << endl;
	cout << (c + d).Simplification() << endl;
	return 0;
}