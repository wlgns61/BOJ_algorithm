#include <iostream>
#include <string>

using namespace std;

int main() {
	string word;
	cin >> word;
	int count = 0;
	int i = 0;
	while (i < word.size()) {
		if (word[i] == 'c' && word[i + 1] == '=') {
			count++;
			i = i + 2;
		}
		else if (word[i] == 'c' && word[i + 1] == '-') {
			count++;
			i = i + 2;
		}
		else if (word[i] == 'd' && word[i + 1] == 'z' && word[i + 2] == '=') {
			count++;
			i = i + 3;
		}
		else if (word[i] == 'd' && word[i + 1] == '-') {
			count++;
			i = i + 2;
		}
		else if (word[i] == 'l' && word[i + 1] == 'j') {
			count++;
			i = i + 2;
		}
		else if (word[i] == 'n' && word[i + 1] == 'j') {
			count++;
			i = i + 2;
		}
		else if (word[i] == 's' && word[i + 1] == '=') {
			count++;
			i = i + 2;
		}
		else if (word[i] == 'z' && word[i + 1] == '=') {
			count++;
			i = i + 2;
		}
		else {
			count++;
			i++;
		}
	}
	cout << count;
}