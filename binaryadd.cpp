//int 正数最大 01111111 11111111 11111111 1111111   2^31-1
//int 负数最大 10000000 00000000 00000000 0000000    - 2^31
//				负数 由 取反+1
#include <iostream>

using namespace std;

int addBinary(int x){
	for (int i = 0, check = 1; i < sizeof(int) * 8; check = check << 1, i++){
		if ((x & check) == 0){
			x = x ^ check;
			break;
		}
		else{
			x = x &(~check);
		}
	}
	return x;
}


int main(int argc, char**argv){
	int x = 1;
	x << 1;
	cout << x << endl; // x remain unchanged
	cout << sizeof(int) << endl;
	int y = 0;
	for (int i = 0; i < sizeof(int) * 8; y = y << 1,i++){
		y = y +1;
		cout << y << endl;	
	}
	cout << ~0 << endl;

	cout << "x = 1 :" << addBinary(x) << endl;
	cout << "x = INT_MAX :" << addBinary(INT_MAX) << endl;
	cout << "x = INT_MIN :" << addBinary(INT_MIN) << endl;
	cout << "x = -1 :" << addBinary(-1) << endl;
	cout << "x = 0 :" << addBinary(0) << endl;
	
	getchar();
}