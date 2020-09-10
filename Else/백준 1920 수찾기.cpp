#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
long long arr[100000];

int findNum(long long num) {

	int start = 0;
	int end = n - 1;
	int result = 0;

	while (end >= start) {
		int mid = (start + end) / 2;
		if (arr[mid] < num) {
			start = mid + 1;
		}
		else {
			if (arr[mid] == num) {
				result = 1;
				break;
			}
			end = mid - 1;
		}
	}
	return result;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr+n);
	cin >> m;
	for (int i = 0; i < m; i++) {
		long long num;
		cin >> num;
		cout << findNum(num) <<"\n";
	}
	
}