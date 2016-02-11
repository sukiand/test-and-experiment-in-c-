#include <iostream>

using namespace std;

void test(const char *A){
	if (*A ) cout << *A<<endl;
	else cout << "no *A" << endl;

	if (*(A + 1)) cout << *(A + 1);
	else cout << "no *(A+1)" << endl;

	if (*(A + 2)) cout << *(A + 2);
	else cout << "no *(A+2)" << endl;


	if (A) cout << "A is :"<<A << endl;
	else cout << "no A" << endl;
}

void main(){
	for (int i = 1; i < 10; i == 10 ? i: i++){
		cout << i;
	}
	cout << endl;

	for (int i = 1; i < 10; i = i == 10 ? i : i+1){
		cout << i;
	}
	cout << endl;

	for (int i = 1; i < 10; i = i==10? i: ++i){
		cout << i;
	}
	cout << endl;

	test("");
	//test(NULL);
	test("T");
	getchar();
}