#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;



bool findDictionary(string target, set<string> & dic){
	vector<bool> flag = {};
	for (int i = 0; i < target.size(); i++){
		string l;
		l = target.substr(0, i + 1);
		if (dic.find(l) != dic.end()){
			flag.push_back(i);
			continue;
		}
		if (!flag.empty()){
			for (int j = flag.size()-1; j >= 0; j--){
				int index = flag[j] + 1;
				l = target.substr(index, i - index + 1);
				if (dic.find(l) != dic.end()){
					flag.push_back(i);
					break;
				}
			}
		}
	}
	return flag.back();
}

void findDicDeepSearch(int start, vector<string> &tmp, vector<vector<string>> &result, 
	string target, set<string> & dic){
	
	if (start >= target.size()){
		result.push_back(tmp);
		return;
	}

	for (int i = start; i < target.size(); i++){
		string l = target.substr(start, i - start + 1);
		if (dic.find(l) != dic.end()){
			tmp.push_back(l);
			findDicDeepSearch(i + 1, tmp, result, target, dic);
			tmp.pop_back();
		}
	}
}

void findDicMain(string target, set<string> &dic){
	vector<string> tmp = {};
	vector<vector<string>> result = {};
	findDicDeepSearch(0, tmp, result,target, dic);


	for (int i = 0; i < result.size(); i++){
		string outp = "";
		for (int j = 0; j < result[i].size(); j++){
			outp += " " + result[i][j];
		}
		cout << outp << endl;
	}
	//cout << "test";
}



int main(int argc, char** argv){
	set<string> dic;
	dic.insert("I");
	dic.insert("ILO");
	dic.insert("VE");
	dic.insert("ILOVE");
	dic.insert("LOVE");
	dic.insert("MONGOES");
	string target = "ILOVE";
	if (findDictionary(target, dic)) {
		cout << "find it";
	}
	else{
		cout << "error";
	}
	cout << endl << endl;
	findDicMain(target, dic);

	getchar();
	return 1;
}