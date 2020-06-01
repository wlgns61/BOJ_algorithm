#include <iostream>
#include <cmath>
using namespace std;

int **ability;
bool *choosen;
int N;
int *team1;
int *team2;
int min_ = 4000001;

void print_out() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << ability[i][j] << " ";
		}
		cout << "\n";
	}
}

void make_ability_table() {

	ability = new int*[N];
	choosen = new bool[N];
	for (int i = 0; i < N; i++) {
		ability[i] = new int[N];
		choosen[i] = false;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int stat;
			cin >> stat;
			ability[i][j] = stat;
		}
	}
}

int find_result() {
	int result1 = 0; int result2 = 0;
	for (int i = 0; i < N/2; i++) {
		for (int j = 0; j < N/2; j++) {
			if (i == j) continue;
			result1 += ability[team1[i]][team1[j]];
			result2 += ability[team2[i]][team2[j]];
		}
	}
	return abs(result1 - result2);
}

void find_min(int cnt, int index) {
	if (cnt == N / 2) {
		int j = 0; int sum1 = 0; int sum2 = 0;
		for (int i = 0; i < N; i++) { // 
			if (choosen[i] == false) {
				team2[j++] = i;
			}
		}
		if (find_result() <= min_) min_ = find_result();
		return;
	}
	else {
		for (int i = index; i < N; i++) {
			if (choosen[i] == false) {
				choosen[i] = true;
				team1[cnt] = i;
				find_min(cnt + 1, i);
				choosen[i] = false;
			}
		}
	}
}

int main() {
	
	cin >> N;
	make_ability_table();
	team1 = new int[N / 2];
	team2 = new int[N / 2];
	find_min(0, 0);
	cout << min_;
}