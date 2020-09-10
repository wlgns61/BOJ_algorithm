#include <iostream>
#include <string>
#include <vector>
#define MAX 360000

using namespace std;


vector<int> getpi(vector<bool> p) {
	vector<int> pi(p.size(), 0);
	int j = 0;
	for (int i = 1; i < p.size(); i++) {
		while (p[i] != p[j] && j > 0)
			j = pi[j - 1];
		if (p[i] == p[j])
			pi[i] = ++j;
	}
	return pi;
}

void kmp(vector<bool> clk1, vector<bool> clk2) {
	auto pi = getpi(clk2);
	int j = 0;
	for (int i = 0; i < clk1.size(); i++) {
		while (clk1[i] != clk2[j] && j > 0)
			j = pi[j - 1];
		if (clk1[i] == clk2[j]) {
			if (j == clk2.size() - 1) {
				cout << "possible";
				return;
			}
			else
				j++;
		}
	}
	cout << "impossible";
	return;
}

int main() {

	vector<bool> clock1(MAX * 2, false);
	vector<bool> clock2(MAX, false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int point;
		cin >> point;
		clock1[point] = clock1[point + MAX] = true;
	}
	for (int i = 0; i < n; i++) {
		int point;
		cin >> point;
		clock2[point] = true;
	}
	kmp(clock1, clock2);
}