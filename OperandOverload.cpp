#include <iostream>
#include <vector>

using namespace std;

class Inner{
public:
	int x;
	int y;
	Inner(int a, int b){
		x = a;
		y = b;
	}
	Inner operator + (Inner &a){
		int c = x + a.x;
		int d = y + a.y;
		return Inner(c, d);
	}
	Inner operator - (Inner &a){
		int c = x - a.x;
		int d = y - a.y;
		return Inner(c, d);
	}
	void show(){
		cout << "зјБъ(" << x << "," << y << ")" << endl;
	}
};

int main(int argc, char ** argv){
	Inner a(2, 1);
	Inner b(0, 1);
	Inner c = b - a;
	c.show();
	b.show();
	getchar();
}
