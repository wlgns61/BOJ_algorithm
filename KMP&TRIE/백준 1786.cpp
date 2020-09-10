#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <int> getpi(string pattern) {
	vector <int> pi(pattern.size(), 0);
	int j = 0;
	for (int i = 1; i < pattern.size(); i++) {
		while (0 < j && pattern[j] != pattern[i])
			j = pi[j - 1];
		if (pattern[j] == pattern[i]) 
			pi[i] = ++j;
	}
	return pi;
}

vector <int> kmp(string text, string pattern) {
	vector <int> ans;
	vector <int> pi = getpi(pattern);
	int j = 0;
	for (int i = 0; i < text.size(); i++) {
		while (j > 0 && text[i] != pattern[j])
			j = pi[j - 1];
		if (pattern[j] == text[i]) {
			if (j == pattern.size() - 1) { //���� �� ��ġ ���� ��
				ans.push_back(i - (pattern.size() - 2));
				j = pi[j]; // �Ϸ��� ���̾ ��ġ�� �κ� ���� Ž���ϱ� ����
			}
			else 
				j++;
		}
	}
	return ans;
}

int main() {
	string T; // ��ü
	string P; // ����
	vector <int> V;
	getline(cin, T);
	getline(cin, P);
	vector <int> ans = kmp(T, P);
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
}