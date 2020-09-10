#include <iostream>
#include <vector>

using namespace std;

vector <int> v;

int lower_bound(int num) {
	int start = 0;
	int end = v.size() - 1;
	int mid;
	int result = 0;
	while (end - start >= 0) {
		mid = (start + end) / 2;
		if (v[mid] < num) {
			start = mid + 1;
		}
		else {
			result = mid;
			end = mid - 1;
		}
	}
	return result;
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		if (v.empty()) {
			v.push_back(num);
		}
		else {
			if (v.back() < num) {
				v.push_back(num);
			}
			else {
				int idx = lower_bound(num);
				v[idx] = num;
			}
		}
	}
	cout << v.size();
}