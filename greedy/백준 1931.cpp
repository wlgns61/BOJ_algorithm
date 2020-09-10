#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> time_table;

bool compare(pair<int, int> &a, pair<int, int> &b) {
	if (a.second == b.second)
		return a.first < b.first;
	else 
		return a.second < b.second;
}

int main() {
	int N;
	int cnt = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int start, finish;
		cin >> start >> finish;
		time_table.push_back(make_pair(start, finish));
	}
	sort(time_table.begin(), time_table.end(), compare);
	int last = 0;
	for (int i = 0; i < N; i++) {
		if (time_table[i].first >= last) {
			last = time_table[i].second;
			cnt++;
		}
	}
	cout << cnt;
}