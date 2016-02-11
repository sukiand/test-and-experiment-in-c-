#include <iostream>
#include <vector>

using namespace std;

class Pos{
public:
	vector<int> setx;
	vector<int> sety;
	Pos(vector<int>, vector<int>);
	Pos operator +(Pos &);
	void show();
};