#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[1000001];
vector <int> v;
pair <int, int> track[1000001]; //vector_pos, value

void solve(int n) {
	v.push_back(arr[0]);
	track[0] = { v.size() - 1, arr[0] };
	for (int i = 0; i < n; i++) {
		if (v[v.size() - 1] < arr[i]) {
			v.push_back(arr[i]);
			track[i] = { v.size() - 1, arr[i] };
		}
		else {
			int start = 0, result = 0;
			int end = v.size() - 1;
			while (end - start >= 0) {
				int mid = (start + end) / 2;
				if (v[mid] < arr[i]) {
					start = mid + 1;
				}
				else {
					result = mid;
					end = mid - 1;
				}
			}
			v[result] = arr[i];
			track[i] = { result, arr[i] };
		}
	}
}

void print(int n) {
	vector <int> print_v;
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