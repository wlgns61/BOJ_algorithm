#include <iostream>
#include <string>

using namespace std;

int find_number(int index) {
	int num = 0;
	if (index >= 22) num = 9;
	else if (index >= 19) num = 8;
	else if (index >= 15) num = 7;
	else if (index >= 12) num = 6;
	else if (index >= 9) num = 5;
	else if (index >= 6) num = 4;
	else if (index >= 3) num = 3;
	else if (index >= 0) num = 2;
	return num;
}

int main() {

	string word;
	cin >> word;
	int i = 0; int num = 0; int time = 0;
	int total_time = 0;
	int index = -1;
	for (i = 0; i < word.size(); i++) {
		index = int(word[i]) - int('A');
		num = find_number(index);
		time = num + 1;
		total_time += time;
	}
	cout << total_time;
}