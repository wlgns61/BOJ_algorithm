#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector <int> getpi(string pattern) {

	vector <int> pi(pattern.size(), 0);
	int j = 0; // �� ������� Ŀ��

	for (int i = 1; i < pattern.size(); i++) {
		while (0 < j && pattern[i]!=pattern[j]) {
			j = pi[j - 1];
		}
		if (pattern[i] == pattern[j]) {
			pi[i] = ++j; // j�� �ε����̱� ���� j+1�� ������ �ش��ϸ�, j+1�� ���� �ε����� ��
		}
	}
	return pi;
}

vector<int> find_pattern(string text, string pattern) {
	
	vector <int> pi = getpi(pattern);
	vector <int> result;
	int j = 0;

	for (int i = 0; i < text.size(); i++) {
		while (0 < j &&  text[i] != pattern[j]) {
			j = pi[j - 1];
		}
		if (text[i] == pattern[j]) {
			if (j == pattern.size() - 1) {
				result.push_back(i - j + 1);
				j = pi[j];
			}
			else {
				j++;
			}
		}
	}
	return result;
}

int main() {

	string text;
	string pattern;
	getline(cin, text);
	getline(cin, pattern);

	vector <int> result = find_pattern(text, pattern);
	cout << result.size() << "\n";
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}

}