#include <iostream>
#include <string>

using namespace std;

int main() {

	string word;
	cin >> word;
	int arr[26];
	int i = 0; int index = 0;
	for (i = 0; i < 26; i++) {
		arr[i] = -1;
	}
	for (i = 0; i < word.size(); i++) {
		index = int(word[i]) - int('a');
		if (arr[index] == -1)
			arr[index] = i;
	}
	for (i = 0; i < 26; i++) {
		cout << arr[i] << " ";
	}
}