#include <iostream>
#include <string>

using namespace std;

int main() {
	int num; int i; int j; int index; 
	int flag = 1; int count = 0;
	string word;
	cin >> num;
	for (i = 0; i < num; i++) {
		int alphabet[26] = { 0 };
		flag = 1;
		cin >> word;
		index = int(word[0]) - int('a');
		alphabet[index]++;
		for (j = 1; j < word.size(); j++) {
			index = int(word[j]) - int('a');
			if (word[j] != word[j - 1]) {
				alphabet[index]++;
				if (alphabet[index] > 1) {
					flag = 0;
					break;
				}
			}
		}
		if (flag == 1) {
			count++;
		}
	}
	cout << count;
}