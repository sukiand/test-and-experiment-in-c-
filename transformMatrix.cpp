#include <iostream>
#include <vector>

using namespace std;

void printMatrix(vector<vector<int>> &m){
	for (int i = 0; i < m.size(); i++){
		for (int j = 0; j < m[0].size(); j++){
			cout << m[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

vector<vector<int>> transformMatrix(vector<vector<int>> &m, int flag){
	int line = m.size();
	int col = m[0].size();
	vector<vector<int>> result(col, vector<int>(line, 0));
	for (int i = 0; i < m.size(); i++){
		for (int j = 0; j < m[0].size(); j++){
			if (flag == 1){
				result[j][line-i-1] = m[i][j];
			}
			else{
				result[col - j-1][i] = m[i][j];
			}
		}
	}
	return result;
}

int main(int argc, char ** argv){
	vector<vector<int>> matrix(5, vector<int>(3, 0));
	for (int i = 0; i < matrix.size(); i++){
		for (int j = 0; j < matrix[0].size(); j++){
			matrix[i][j] = i+j;
		}
	}
	printMatrix(matrix);
	vector<vector<int>> matrixA = transformMatrix(matrix, 1);
	printMatrix(matrixA);
	vector<vector<int>> matrixB = transformMatrix(matrix, -1);
	printMatrix(matrixB);
	getchar();
}