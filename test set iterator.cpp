#include <iostream>
#include <set>

using namespace std;

void main(){
	set<int> test{ 1, 2, 3, 4, 5 };
	for (auto i = test.begin(); i != test.end(); i++){
		cout << *i << " ";
		if (*i == 3){
			test.erase(i);
			i = test.begin();
		}
	}
	getchar();
}