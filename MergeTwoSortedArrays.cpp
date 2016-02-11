//����ڳ����ж�vector�е�Ԫ�������޸ģ���ӻ���ɾ��Ԫ��֮�󣬵������ͻ�ʧЧ����ʱ��Ͳ�Ҫʹ�õ������ˡ�
#include <iostream>
#include <vector>

using namespace std;

vector<int> mergesort(const vector<int> &a, const vector<int> &b){
	vector<int>::const_iterator i, j; //  const vector ֻ���� const_iterator ������
	i = a.begin();
	j = b.begin();
	vector<int> result;
	while (i != a.end() && j != b.end()){
		if (*i < *j){
			result.push_back(*i);
			i++;
		}
		else{
			result.push_back(*j);
			j++;
		}
	}
	while (j != b.end()){
		result.push_back(*j);
		j++;
	}
	while (i != a.end()){
		result.push_back(*i);			
		i++;
	}
	return result;
}

void printVector(const vector <int> &k){
	vector<int>::const_iterator t;
	for (t = k.begin(); t != k.end(); t++){
		cout << *t << " ";
	}
	cout << endl;
}

int main(int argc, char ** argv){
	vector<int> a = { -1 };
	//printVector(a);
	//cout << a.size() << endl;
	//cout << *a.begin() << endl;
	//cout << *(a.begin() + 1) << endl;
	//a.insert(a.begin(), 100);
	//a.insert(a.begin()+1, 200);
	//a.insert(a.end()-1, 20);
	//printVector(a);
	vector<int> b = { 0,9 };
	a = mergesort(a, b);
	printVector(a);
	getchar();
}