#include <iostream>

using namespace std;

int main() {
	int n = 0, i = 0; float score = 0, max = 0, sum = 0, avg = 0;
	cin >> n;
	int *score_table = new int[n];
	for (i = 0; i < n; i++) {
		score_table[i] = 0;
		cin >> score;
		if (max < score) 
			max = score;
		score_table[i] = score;
	}
	for (i = 0; i < n; i++) {
		score = (score_table[i]/max) * 100;
		sum += score;
		score_table[i] = score;
	}
	avg = sum / n;
	cout << avg << endl;

}