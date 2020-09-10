#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector <int> getpi(string text) {
	vector <int> pi(text.size(), 0);
	int j = 0;
	for (int i = 1; i < text.size(); i++) {
		while (text[i] != text[j] && j > 0) 
			j = pi[j - 1];
		if (text[i] == text[j]) 
			pi[i] = ++j;
	}
	return pi;
}

int main() {
	string text; int len;
	cin >> len >> text;
	auto pi = getpi(text);
	cout << len - pi.back();
}