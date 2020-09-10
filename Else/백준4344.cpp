#include <iostream>

using namespace std;

int main() {
	int C, N;
	int i = 0, j = 0, count = 0;
	cin >> C;
	int sum = 0;
	float *percent_arr = new float[C];
	float avg=0;
	for (i = 0; i < C; i++) {
		cin >> N;
		sum = 0; avg = 0; count = 0;
		int *score_arr = new int[N];
		for (j = 0; j < N; j++) {
			cin >> score_arr[j];
			sum += score_arr[j];
		}
		avg = double(sum) / N;
		for (j = 0; j < N; j++) {
			if (avg < score_arr[j]) {
				count++;
			}
		}
		percent_arr[i] = (float(count) / float(N)) * 100.0;
	}
	for (i = 0; i < C; i++) {
		cout.setf(ios::showpoint);
		cout.precision(5);
		cout << percent_arr[i] << "%" << endl;
	}
}