#include <iostream>
#include <string>

using namespace std;

int main(){
	int i = 0; int j = 0;
	int line = 0;
	cin >> line;
	int score = 0, score_sum = 0;
	int *score_arr = new int[line];
	string ox_result = "\0";
	for (j = 0; j < line; j++) {
		cin >> ox_result;
		score_sum = 0;
		score = 0;
		for (i = 0; i < ox_result.length(); i++) {
			if (ox_result[i] == 'O') {
				score++;
				score_sum += score;
			}
			else if (ox_result[i] == 'X') {
				score = 0;
			}
		}
		score_arr[j] = score_sum;
	}
	for (j = 0; j < line; j++) {
		cout << score_arr[j] << endl;
	}
	
}