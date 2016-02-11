#include "OperandOverloadOut.h"

Pos::Pos(vector<int> a, vector<int> b){
	this->setx = a;
	this->sety = b;
}

Pos Pos::operator+(Pos &k){
	vector<int> m, n;
	m = this->setx;
	for (int i = 0; i < k.setx.size(); i++){
		m.push_back(k.setx[i]);
	}

	n = this->sety;
	for (int i = 0; i < k.sety.size(); i++){
		n.push_back(k.sety[i]);
	}

	return Pos(m, n);
}

void Pos::show(){
	for (int i = 0; i < this->setx.size(); i++){
		cout << this->setx[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < this->sety.size(); i++){
		cout << this->sety[i] << " ";
	}
	cout << endl;

}

int main(int argc, char ** argv){
	vector<int> x,y;
	x.push_back(1);
	x.push_back(2);
	x.push_back(3);
	y.push_back(9);
	y.push_back(8);
	Pos a1(x, y);
	x.push_back(10);
	Pos a2(x, y);
	a1.show();
	a2.show();
	a1 = a1 + a2;
	a1.show();
	getchar();
}
