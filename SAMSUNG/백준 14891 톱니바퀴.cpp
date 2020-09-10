#include <iostream>
#include <cmath>
#include <string.h>

using namespace std;
int gear[4];
bool visited[4];
int t;

void rotation(int &gear, int dir){
	if (dir == 1) { //시계
		int tmp = 0; 
		if ((gear & (1 << 7)) == (1 << 7)) tmp = 1;
		else tmp = 0;
		gear = (gear << 1) & ((1 << 8) - 1);
		gear |= tmp;
	}
	else { //시계 반대
		int tmp = (gear & 1);
		gear = (gear >> 1);
		gear |= (tmp << 7);
	}
}

bool isturn(int low, int high) { //극이 반대면 return true
	int bit1 = 0;
	int bit2 = 0;
	if ((gear[low] & (1 << 2)) == (1 << 2)) bit1 = 1;
	if ((gear[high] & (1 << 6)) == (1 << 6)) bit2 = 1;
	if(bit1 == bit2)
		return false;
	return true;
}

void query(int idx, int dir) {
	visited[idx] = true;
	if ((idx - 1) >= 0 && !visited[idx - 1] && isturn(idx - 1, idx))
		query(idx - 1, -1 * dir);
	if ((idx + 1) < 4 && !visited[idx + 1] && isturn(idx, idx + 1))
		query(idx + 1, -1 * dir);
	rotation(gear[idx], dir);
}

void input() {
	for (int idx = 0; idx < 4; idx++) 
		for (int i = 0; i <= 7; i++) {
			int val;
			scanf("%1d", &val);
			gear[idx] |= (val << i);
		}
}

int find_ans() {
	int ret = 0;
	for (int i = 0; i < 4; i++) 
		if ((gear[i] & 1) == 1)
			ret += int(pow(2, i));
	return ret;
}

int main() {
	input();
	cin >> t;
	while (--t >= 0) {
		int num, dir;
		cin >> num >> dir;
		memset(visited, false, sizeof(visited));
		query(num - 1, dir);
	}
	cout << find_ans() << "\n";
}