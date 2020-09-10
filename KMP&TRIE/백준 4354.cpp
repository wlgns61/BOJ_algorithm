#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector <int> getpi(string text) {
	vector <int> pi(text.size(), 0);
	int j = 0;
	for (int i = 1; i < text.size(); i++) {
		while (j > 0 && text[j] != text[i]) {
			j = pi[j - 1];
		}
		if (text[j] == text[i]) {
			pi[i] = ++j;
		}
	}
	return pi;
}

int main() {
	string text;
	while (true) {
		getline(cin, text);
		if (text.compare(".") == 0)
			return 0;
		auto pi = getpi(text);
		int len = text.size() - pi.back();
		if (len == 0) {
			cout << text.size() << "\n";
		}
		else if (text.size() / 2 > pi.back() || text.size() % len != 0) {
			cout << 1 << "\n";
		}
		else {
			cout << text.size()/len << "\n";
		}
	}
}
