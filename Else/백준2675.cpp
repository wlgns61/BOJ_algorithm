#include <iostream>
#include <string>

using namespace std;

int main() {
	string word = "";
	string new_word = "";
	int n=1, i=0, j=0, k=0;
	int test_case = 0;
	cin >> test_case;
	for (k = 0; k < test_case; k++) {
		cin >> n >> word;
		new_word = "";
		for (i = 0; i < word.size(); i++) {
			for (j = 0; j < n; j++) {
				new_word += word[i];
			}
		}
		cout << new_word << endl;
	}
}