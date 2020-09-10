#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool comp(pair<int, string> a, pair<int, string> b) {
	if (a.first < b.first)
		return true;
	return false;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	vector <pair<int, string>> info;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int age;
		string name;
		cin >> age >> name;
		info.push_back({ age, name });
	}
	stable_sort(info.begin(), info.end(), comp);
	for (int i = 0; i < info.size(); i++) {
		cout << info[i].first << " " << info[i].second << "\n";
	}
}