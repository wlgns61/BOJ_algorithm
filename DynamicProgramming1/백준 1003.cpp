#include <iostream>
#include <vector>

using namespace std;
vector<pair<int, int>> arr;

void zero_one(int N) {
	for (int i = 2; i <= N; i++) {
		int zero, one;
		zero = arr[i - 1].first + arr[i - 2].first;
		one = arr[i - 1].second + arr[i - 2].second;
		arr.push_back(make_pair(zero, one));
	}
}

int main() {
	int t_case;
	cin >> t_case;
	for (int i = 0; i < t_case; i++) {
		int N;
		cin >> N;
		arr.push_back(make_pair(1, 0));
		arr.push_back(make_pair(0, 1));
		zero_one(N);
		cout << arr[N].first << " " << arr[N].second << "\n";
		arr.clear();
	}

}