#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int *num_table;

int find_result(int n){
	if (n <= 3) {
		return num_table[n];
	}
	for (int i = 4; i <= n; i++) {
		num_table[i] = num_table[i - 1] + 1;

		if (i % 2 == 0) 
			num_table[i] = min(num_table[i], num_table[i / 2] + 1);
		if (i % 3 == 0) 
			num_table[i] = min(num_table[i], num_table[i / 3] + 1);
	}
	return num_table[n];
}

int main() {
	int N;
	cin >> N;
	num_table = new int[N + 1];
	for (int i = 0; i < N + 1; i++) {
		num_table[i] = 0;
	}
	if (N >= 2)
		num_table[2] = 1;
	if (N >= 3)
		num_table[3] = 1;
	cout << find_result(N);
}

