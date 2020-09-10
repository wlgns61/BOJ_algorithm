#include <iostream>
#include <vector>

using namespace std;

int row, col;
int r, c, k;
int map[1001][1001];

void R() {
	for (int i = 1; i <= col; i++) {
		
	}
}

void C() {

}

void solve() {
	if (row >= col) {
		R();
	}
	else {
		C();
	}
}

int main() {
	cin >> r >> c >> k;
	row = 3;
	col = 3;

	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> map[i][j];
		}
	}
}