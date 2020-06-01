#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int **table;
string a;
string b;

int LCS(int row, int col) {
	int result = 0;
	for (int i = 1; i < row+1; i++) {
		for (int j = 1; j < col+1; j++) {
			if (a[i - 1] == b[j - 1]) {
				table[i][j] = table[i - 1][j - 1] + 1;
				result = max(result, table[i][j]);
			}
			else {
				table[i][j] = max(table[i-1][j], table[i][j-1]);
				result = max(result, table[i][j]);
			}
		}
	}
	return result;
}

int main() {
	cin >> a >> b;
	table = new int*[a.size()+1];
	for (int i = 0; i < a.size()+1; i++) {
		table[i] = new int[b.size()+1];
	}
	for (int i = 0; i < a.size()+1; i++) {
		for (int j = 0; j < b.size()+1; j++) {
			table[i][j] = 0;
		}
	}
	cout << LCS(a.size(), b.size());
	
}