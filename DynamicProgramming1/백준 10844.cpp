#include <iostream>
#define MOD 1000000000

using namespace std;

long long new_table[10] = { 0,1,1,1,1,1,1,1,1,1 };
long long past_table[10] = { 0,1,1,1,1,1,1,1,1,1 };

long find_result() {
	long long result = 0;
	for (int i = 0; i < 10; i++) {
		result += new_table[i] % MOD;
	}
	return result % MOD;
}

long update_table(int N) {
	for (int i = 1; i < N; i++) {
		new_table[0] = past_table[1] % MOD;
		new_table[9] = past_table[8] % MOD;
		for (int i = 1; i < 9; i++) {
			new_table[i] = past_table[i - 1] % MOD + past_table[i + 1] % MOD;
		}
		for (int i = 0; i < 10; i++) {
			past_table[i] = new_table[i];
		}
	}
	return find_result();
}

int main() {
	int N;
	cin >> N;
	cout << update_table(N);
}