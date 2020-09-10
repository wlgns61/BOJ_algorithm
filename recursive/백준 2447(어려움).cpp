#include <iostream>

using namespace std;

char map[2300][2300] = { ' ' };

void init() {
	int i, j;
	for (i = 0; i < 3000; i++) {
		for (j = 0; j < 3000; j++) {
			map[i][j] = ' ';
		}
	}
}

void pattern(int n, int x, int y) {
	int i,j;
	if (n == 1) {
		map[x][y] = '*';
		return;
	}
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if (i == 1 && j == 1) continue;
			pattern(n / 3, x + (i*n / 3), y + (j*n / 3));
		}
	}
}

int main() {
	int n = 0;
	cin >> n;
	int i, j;
	init();
	pattern(n,0,0);
	for (i = 0; i< n; i++) {
		for (j = 0; j < n; j++) {
			cout << map[i][j];
		}
		if (i == n-1) break;
		cout << endl;
	}
}


