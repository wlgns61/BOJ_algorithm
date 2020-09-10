#include <iostream>
#include <algorithm>
using namespace std;
int map[101][101];
int n, l;
int cnt = 0;

bool check_row(int row) { //row를 고정

	bool flag = true;
	int col = 0;
	int finished = -1;

	while(col < n - 1){
		if (abs(map[row][col] - map[row][col + 1]) > 1)
			return flag = false;
		else if (map[row][col] - map[row][col + 1] == 1) { //현재의 경사가 높은 경우 -> 내려가야댐
			if (col + l >= n)   //경사로를 깔아야 될 자리가 부족하다면
				return flag = false; 
			else {   
				for (int i = col + 1; i <= col + l; i++) { //경사로를 깔자리들이 평평한지 확인
					if (map[row][col + 1] != map[row][i])
						return flag = false;
				}
				col += l; 
				finished = max(col, finished); //완료가 된 지점
			}
		}
		else if((map[row][col + 1] - map[row][col] == 1)){ // 다음의 경사가 높은 경우 -> 올라가야댐
			if (col - l + 1 <= finished) //경사로를 깔기위한 구간이 현재작업이 완료된공간에 포함된다면
				return flag = false;
			else {
				for (int i = col - l + 1; i < col; i++) { //경사로를 깔자리들이 평평한지 확인
					if (map[row][i] != map[row][col])
						return flag = false;
				}
				finished = max(col, finished);
				col++;
			}
		}
		else
			col++;
	}
	return flag;
}

bool check_col(int col) { //col을 고정

	bool flag = true;
	int row = 0;
	int finished = -1;

	while (row < n - 1) {
		if (abs(map[row][col] - map[row + 1][col]) > 1)
			return flag = false;
		else if (map[row][col] - map[row + 1][col] == 1) { //현재의 경사가 높은 경우 -> 내려가야댐
			if (row + l >= n)   //경사로를 깔아야 될 자리가 부족하다면
				return flag = false;
			else {
				for (int i = row + 1; i <= row + l; i++) { //경사로를 깔자리들이 평평한지 확인
					if (map[row + 1][col] != map[i][col])
						return flag = false;
				}
				row += l;
				finished = max(row, finished);
			}
		}
		else if ((map[row + 1][col] - map[row][col] == 1)) { // 다음의 경사가 높은 경우 -> 올라가야댐
			if (row - l + 1 <= finished) //경사로를 깔기위한 구간이 현재작업이 완료된공간에 포함된다면
				return flag = false;
			else {
				for (int i = row - l + 1; i < row; i++) { //경사로를 깔자리들이 평평한지 확인
					if (map[i][col] != map[row][col])
						return flag = false;
				}
				finished = max(row, finished);
				row++;
			}
		}
		else
			row++;
	}
	return flag;
}

void solve() {
	for (int i = 0; i < n; i++) {
		if (check_row(i)) {
			//cout << "garo : " << i << endl;
			cnt++;
		}
	}
	for (int i = 0; i < n; i++) {
		if (check_col(i)) {
			//cout << "sero : " << i << endl;
			cnt++;
		}
	}
}

int main() {
	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	solve();
	cout << cnt << "\n";
}