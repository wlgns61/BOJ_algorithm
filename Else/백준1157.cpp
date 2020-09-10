#include <iostream>
#include <cctype>
#include <string>

using namespace std;

int main() {
	string word;
	int max = 0; int max_index = 0;
	int arr[26] = { 0 };
	int i = 0; int index = 0; int count = 0;
	cin >> word;
	for (i = 0; i < word.size(); i++) {
		if (int(word[i]) >= int('a')) {
			word[i] = toupper(word[i]);
		}
		index = int(word[i]) - int('A');
		arr[index]++;
	}
	for (i = 0; i < 26; i++) {
		if (max < arr[i]) {
			max = arr[i];
			max_index = i;
		}
	}
	
	for (i = 0; i < 26; i++) {
		if (max == arr[i]) {
			count++;
		}
	}
	if (count > 1) cout << "?" << endl;
	else cout << char(int('A') + max_index);

}
