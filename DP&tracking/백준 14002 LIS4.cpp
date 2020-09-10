#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector <int> v;
int arr[1002];
pair<int, int> track[1002];
vector <int> print_v;

void solve(int n) {

	if (v.empty()) {
		v.push_back(arr[0]);
		track[0] = { 0, arr[0] };
	}
	
	for (int i = 1; i < n; i++) {
		int past = v[v.size() - 1];
		if (past < arr[i]) { //입력이 더 크면 붙음
			v.push_back(arr[i]);
			track[i] = { v.size() - 1, arr[i] };
		}
		else { //입력이 같거나 작으면 대체됨
			int num = arr[i];
			int end = v.size() - 1;
			int start = 0, result = 0;
			while (end - start >= 0) {
				int mid = (start + end) / 2;
				if (v[mid]< num) {
					start = mid + 1;
				}
				else {
					result = mid;
					end = mid - 1;
				}
			}
			v[result]= num;
			track[i] = { result, arr[i] };
		}
	}
}

void print(int n) {
	int pos = v.size() - 1;
	for (int i = n - 1; i >= 0; i--) {
		if (track[i].first == pos) {
			print_v.push_back(track[i].second);
			pos--;
		}
	}
	int len = print_v.size() - 1;
	for (int i = print_v.size() - 1; i >= 0; i--) {
		cout << print_v[i] << " ";
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	solve(n);
	cout << v.size() << endl;
	print(n);
}