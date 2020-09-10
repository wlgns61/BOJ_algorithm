#include <iostream>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

string str1;
string str2;
int dp[1001][1001];
stack <char> track;

void LCS() {
	for (int i = 1; i <= str2.size(); i++) {
		for (int j = 1; j <= str1.size(); j++) {
			if (str1[j - 1] == str2[i - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
}

void find_track() {
	cout << dp[str2.size()][str1.size()] << "\n";
	int len1 = str1.size();
	int len2 = str2.size();
	while (dp[len2][len1] > 0) {
		if (dp[len2][len1] == dp[len2][len1 - 1]) // ¿ÞÂÊ
			len1--;
		else if (dp[len2][len1] == dp[len2 - 1][len1]) //À§ÂÊ
			len2--;
		else if (dp[len2][len1 - 1] == dp[len2 - 1][len1]) {
			track.push(str1[len1 - 1]);
			len1--;
			len2--;
		}
	}
	while (!track.empty()) {
		cout << track.top();
		track.pop();
	}
}



int main() {
	cin >> str1 >> str2;
	LCS();
	find_track();
}