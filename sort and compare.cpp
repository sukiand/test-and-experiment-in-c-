#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct myMap{
	int value;
	int index;
	myMap(int x, int y) : value(x), index(y){}
};

bool com_map(myMap a, myMap b){
	return a.value > b.value;
}

struct com_myMap_class{
	bool operator()(myMap a, myMap b){ return a.value > b.value; }
}com_myMap;

int main(int argc, char ** argv){
	vector<int> init_data = { 7, 4, 1, 6, 9, 3, 1, 10 };
	vector<myMap> m_map;
	for (int i = 0; i < init_data.size(); i++){
		myMap m(init_data[i], i);
		m_map.push_back(m);
	}
	//using sort with bool function
	//sort(m_map.begin(),m_map.end(), com_map);
	//using sort with object. OBJECT!!!not class
	sort(m_map.begin(),m_map.end(), com_myMap);
	for (int i = 0; i < m_map.size(); i++){
		cout << m_map[i].value << " " << m_map[i].index << endl;
	}
	int k = INT_MAX;
	cout << (k << 1);
	getchar();
	
}