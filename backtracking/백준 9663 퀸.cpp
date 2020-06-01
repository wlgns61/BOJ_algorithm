#include <iostream>

using namespace std;

int N;
bool *arr;
bool *right_up; // 같은 대각선상에서 i+j는 일정
bool *left_up;  // 같은 대각선상에서 i-j는 일정
int result = 0;

void n_queens(int i) {
	if (i==N) {
		result++;
	}
	else {
		for (int j = 0; j < N; j++) {
			if (arr[j] == true) continue;
			if (right_up[i + j] == true || left_up[N - 1 - (i - j)] == true) continue;
			arr[j] = right_up[i + j] = left_up[N - 1 - (i - j)] = true;
			n_queens(i + 1);
			arr[j] = right_up[i + j] = left_up[N - 1 - (i - j)] = false;
		}
	}
}

int main() {
	cin >> N;
	arr = new bool[N];
	right_up = new bool[2*N-1];
	left_up = new bool[2*N-1];
	n_queens(0);
	cout << result;
}
