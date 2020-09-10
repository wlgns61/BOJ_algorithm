#include <iostream>
#include <algorithm>
using namespace std;
int map[101][101];
int n, l;
int cnt = 0;

bool check_row(int row) { //row�� ����

	bool flag = true;
	int col = 0;
	int finished = -1;

	while(col < n - 1){
		if (abs(map[row][col] - map[row][col + 1]) > 1)
			return flag = false;
		else if (map[row][col] - map[row][col + 1] == 1) { //������ ��簡 ���� ��� -> �������ߴ�
			if (col + l >= n)   //���θ� ��ƾ� �� �ڸ��� �����ϴٸ�
				return flag = false; 
			else {   
				for (int i = col + 1; i <= col + l; i++) { //���θ� ���ڸ����� �������� Ȯ��
					if (map[row][col + 1] != map[row][i])
						return flag = false;
				}
				col += l; 
				finished = max(col, finished); //�Ϸᰡ �� ����
			}
		}
		else if((map[row][col + 1] - map[row][col] == 1)){ // ������ ��簡 ���� ��� -> �ö󰡾ߴ�
			if (col - l + 1 <= finished) //���θ� ������� ������ �����۾��� �Ϸ�Ȱ����� ���Եȴٸ�
				return flag = false;
			else {
				for (int i = col - l + 1; i < col; i++) { //���θ� ���ڸ����� �������� Ȯ��
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

bool check_col(int col) { //col�� ����

	bool flag = true;
	int row = 0;
	int finished = -1;

	while (row < n - 1) {
		if (abs(map[row][col] - map[row + 1][col]) > 1)
			return flag = false;
		else if (map[row][col] - map[row + 1][col] == 1) { //������ ��簡 ���� ��� -> �������ߴ�
			if (row + l >= n)   //���θ� ��ƾ� �� �ڸ��� �����ϴٸ�
				return flag = false;
			else {
				for (int i = row + 1; i <= row + l; i++) { //���θ� ���ڸ����� �������� Ȯ��
					if (map[row + 1][col] != map[i][col])
						return flag = false;
				}
				row += l;
				finished = max(row, finished);
			}
		}
		else if ((map[row + 1][col] - map[row][col] == 1)) { // ������ ��簡 ���� ��� -> �ö󰡾ߴ�
			if (row - l + 1 <= finished) //���θ� ������� ������ �����۾��� �Ϸ�Ȱ����� ���Եȴٸ�
				return flag = false;
			else {
				for (int i = row - l + 1; i < row; i++) { //���θ� ���ڸ����� �������� Ȯ��
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