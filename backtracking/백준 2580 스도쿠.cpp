#include <iostream>
#include <vector>
#include <utility>

using namespace std;
vector<pair<int, int>> blank;
int sudoku[9][9] = {0};

void make_sudoku() {
	int num;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> num;
			sudoku[i][j] = num;
			if (num == 0) 
				blank.push_back(make_pair(i, j));
		}
	}
}

int check1(int num, int row) { //�� ����
	for (int i = 0; i < 9; i++) {
		if (sudoku[row][i] == num) { //�� �˻�
			return 0;
		}
	}
	return 1;
}

int check2(int num, int col) {  //�� ����
	for (int i = 0; i < 9; i++) {
		if (sudoku[i][col] == num) { //�� �˻�
			return 0;
		}
	}
	return 1;
}

int check3(int num, int row, int col) { // ��,��
	int x = row / 3;
	int y = col / 3;
	x = x * 3;
	y = y * 3;
	for (int i = x; i < x + 3; i++) {
		for (int j = y; j < y + 3; j++) {
			if (sudoku[i][j] == num) { // 3X3�ڽ� �˻�
				return 0;
			}
		}
	}
	return 1;
}

void solve_sudoku(int cnt) {
	if (cnt == blank.size()) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << sudoku[i][j] << " ";
			}
			cout << "\n";
		}
		exit(0);
	}
	else {
		for (int i = 1; i <= 9; i++) { //��ĭ�� ä������ ����
			int x = blank[cnt].first;
			int y = blank[cnt].second;
			if (check1(i, x) * check2(i, y) * check3(i, x, y) == 1) { //������ ��� �����Ҷ�
				sudoku[x][y] = i;
				solve_sudoku(cnt + 1);
				sudoku[x][y] = 0;
			}
		}
	}
}

int main() {
	make_sudoku();
	solve_sudoku(0);
}