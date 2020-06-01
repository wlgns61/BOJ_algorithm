#include <iostream>

using namespace std;

int N;
int *number;
int operators[4] = {0};
int max_ = -1000000000;
int min_ = 1000000000;

void find_min_max(int plus, int minus, int multiply, int divide, int cnt, int result) {
	if (cnt == N) {
		if (max_ <= result) max_ = result;
		if (min_ >= result) min_ = result;
	}
	else {
		if (plus > 0)
			find_min_max(plus - 1, minus, multiply, divide, cnt + 1, result + number[cnt]);
		if (minus > 0)
			find_min_max(plus, minus - 1, multiply, divide, cnt + 1, result - number[cnt]);
		if (multiply > 0)
			find_min_max(plus, minus, multiply - 1, divide, cnt + 1, result * number[cnt]);
		if (divide > 0)
			find_min_max(plus, minus, multiply, divide - 1, cnt + 1, result / number[cnt]);
	}
}

int main() {
	cin >> N;
	number = new int[N];
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		number[i] = num;
	}
	for (int i = 0; i < 4; i++) {
		int token;
		cin >> token;
		operators[i] = token;
	}
	find_min_max(operators[0], operators[1], operators[2], operators[3], 1, number[0]);
	cout << max_ << "\n" << min_;
}