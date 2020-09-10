#include <iostream>
#include <string>

using namespace std;

int word_count(string sentence, int n) {
	int i = 0, count = 0;
	for (i = n; i < sentence.size()-1; i++) {
		if (sentence[i] == ' ' && sentence[i+1]!= ' ') {
			count++;
		}
	}
	return count + 1;
}

int main() {

	int i = 0;
	int count = 0;
	string sentence;
	getline(cin, sentence);
	for (i = 0; i < sentence.size(); i++) {
		if (sentence[i] != ' ') {
			count = word_count(sentence, i);
			break;
		}
	}
	cout << count;

}