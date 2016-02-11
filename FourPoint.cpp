# include <iostream>
#include <math.h>
#include <vector>
#include <map>

using namespace std;

struct Pos{
	int x;
	int y;
};

typedef struct Pos* pos;

int distancesquare(pos p1, pos p2){
	return (p1->x - p2->x)*(p1->x - p2->x) + (p1->y - p2->y)*(p1->y - p2->y);
}

bool calTen(pos a[4]){
	map<int, int> dis;
	for (int i = 0; i < 3; i++){
		for (int j = i + 1; j < 4; j++){
			int var = distancesquare(a[i], a[j]);
			map<int, int>::iterator k = dis.find(var);
			if (k != dis.end()){
				k->second++;
			}
			else{
				dis.insert(make_pair(var,1));
			}
		}
	}
	
	//map<int, int>::iterator l;
	//for (l = dis.begin(); l != dis.end(); l++){
	//	cout << l->first << l->second << endl;
	//}

	if (dis.size() != 2){
		cout << "No!  error 1" << endl;
		return false;
	}
	int line, dline;
	map<int, int>::iterator m;
	for (m = dis.begin(); m != dis.end(); m++){
		if (m->second != 4 && m->second != 2)
		{
			cout << "No! error 2" << endl;
			return false;
		} 
		m->second == 4 ? line = m->first : dline = m->first;
	}
	//cout << line << dline << endl;
	if (dline == 2 * line){
		cout << "Yes!" << endl;
		return true;
	}
	return false;
}

int main(int argc, int ** argv){
	pos a[4];
	for (int i = 0; i < 4; i++){
		a[i] = new Pos();
	}
	a[0]->x = 0;
	a[0]->y = 0;
	a[1]->x = 2;
	a[1]->y = 0;
	a[2]->x = 2;
	a[2]->y = 2;
	a[3]->x = 0;
	a[3]->y = 2;
	calTen(a);
	getchar();
	return 1;
}
