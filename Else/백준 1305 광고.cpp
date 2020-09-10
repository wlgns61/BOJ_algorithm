#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> getpi(string str) {

	vector<int> pi(str.size(), 0);
	int j = 0;

	for (int i = 1; i < pi.size(); i++) {
		while (j > 0 && str[i] != str[j]) {
			j = pi[j - 1];
		}
		if (str[i] == str[j]) {
			pi[i] = ++j;
		}
	}
	return pi;

}

int findMin(string str) {
	return str.size() - getpi(str).back();
}

int main() {

	int L;
	string str;

	cin >> L >> str;
	cout << findMin(str);
	
}