#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <int> arr;
vector <pair<int, int>> countArr;
int n, m;

int numCount(int num) {

	int start = 0;
	int end = countArr.size() - 1;
	int cnt = 0;

	while (start <= end) {

		int mid = (start + end) / 2;

		if (num < countArr[mid].first) {
			end = mid - 1;
		}
		else {
			if (countArr[mid].first == num) {
				cnt = countArr[mid].second;
				break;
			}
			start = mid + 1;
		}
	}
	return cnt;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		arr.push_back(num);
	}

	sort(arr.begin(), arr.end());

	countArr.push_back({ arr[0], 1 });
	for (int i = 1; i < arr.size(); i++) {
		if (countArr.back().first == arr[i]) {
			countArr.back().second++;
		}
		else {
			countArr.push_back({ arr[i],1 });
		}
	}
	
	cin >> m;
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		cout << numCount(num) << " ";
	}
}