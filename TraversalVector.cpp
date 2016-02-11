#include <iostream>
#include <vector>

using namespace std;

#define M_AUTO 1
#define M_ITER 2
#define M_I	3

void travesal1(vector<int> &t, int method){
	if (method == M_AUTO)
	{
		for (auto i : t){
			cout << i << " ";
		}
	}
	else if (method == M_ITER)
	{
		vector<int>::iterator i;
		for (i = t.begin(); i != t.end(); i++){
			cout << *i << " ";  //do not use &i. * is to pick the value of the pointer
		}
	}
	else if (method == M_I){
		vector<int>::size_type i;
		for (i = 0; i < t.size(); i++){
			cout << t[i] << " ";
		}
	}
	else {
		cout << "the parameter is error";
	}
	cout << endl;
}

int main(int argc, char ** argv){
	vector<int> test(20,6);
	cout << "Auto Way : \n\t";
	travesal1(test, M_AUTO);
	cout << "Iterator Way : \n\t";
	travesal1(test, M_ITER);
	cout << "The Lowest Way : \n\t";
	travesal1(test, M_I);
	getchar();
}