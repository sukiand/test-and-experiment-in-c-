#include <iostream>

using namespace std;

class Parent
{
public:
	void foo(){
		cout << "parent foo" << endl;
	}
	void virtual fun(){
		cout << "parent fun" << endl;
	}
};

class child : public Parent
{
public:
	void foo(){
		cout << "child foo" << endl;
	}
	void fun(){
		cout << "child fun" << endl;
	}
};

int main(int argc, char ** argv){
	Parent *A = new Parent();
	A->foo();		//parent foo
	A->fun();		//parent fun
	child *B = new child();
	B->foo();		//child foo
	B->fun();		//child fun
	Parent *C = new child();
	C->foo();		//parent foo
	C->fun();		//child fun
	getchar();
	return 1;
}