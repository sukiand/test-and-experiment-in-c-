#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class MapPhone{
public:
	map<string, vector<string>> a;
	MapPhone(){
		a["1"] = { "a", "b" };
		a["2"] = { "c", "d" };
	}
	void calcu(string s){

	}
	MapPhone operator*(MapPhone &k){
		
	}
};