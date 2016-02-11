#include <iostream>

using namespace std;

int main(int argc, char ** argv){
	int a, b, c, d,k;
	a = 1;
	b = 2;
	c = 3;
	d = 4;
	cout << (1<2)?1:2;
	
	k = a < b?a:c < d?c:d;  //from right to left !!!!
	cout << k << endl;
	getchar();
}