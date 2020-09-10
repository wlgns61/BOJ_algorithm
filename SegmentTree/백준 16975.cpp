#include <iostream>
#include <vector>
#include <cmath>
#define ll long long

using namespace std;
ll result = 0;

void init_tree(vector <ll> &tree, vector <int> &arr, int start, int end, int node) {
	if (start == end) {
		tree[node] = arr[start];
		return;
	}
	int mid = (start + end) / 2;
	init_tree(tree, arr, start, mid, node * 2);
	init_tree(tree, arr, mid + 1, end, node * 2 + 1);
}

void update(vector <ll> &tree, int start, int end, int node, int left, int right, int num) {
	if (start > right || end < left) return;
	if (left <= start && end <= right) {
		tree[node] += num;
		return;
	}
	int mid = (start + end) / 2;
	update(tree, start, mid, node * 2, left, right, num);
	update(tree, mid + 1, end, node * 2 + 1, left, right, num);
}

ll find_idx(vector <ll> &tree, int start, int end, int node, int idx) {

	if (idx < start || idx > end) return 0;
	result += tree[node];
	int mid = (start + end) / 2;
	if (start == end)
		return result;
	return find_idx(tree, start, mid, node * 2, idx) +
		find_idx(tree, mid + 1, end, node * 2 + 1, idx);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m;
	cin >> n;

	int length = int(ceil(log2(n))) + 1;
	length = (1 << length);

	vector <int> arr(n + 1, 0);
	vector <ll> tree(length, 0);
	for (int i = 0; i < n; i++) {
		cin >> arr[i + 1];
	}
	init_tree(tree, arr, 1, n, 1);

	cin >> m;
	for (int i = 0; i < m; i++) {
		int q, a, b, k;
		cin >> q;
		if (q == 1) {
			cin >> a >> b >> k;
			update(tree, 1, n, 1, a, b, k);
		}
		else {
			result = 0;
			cin >> a;
			cout << find_idx(tree, 1, n, 1, a) << "\n";
		}
	}
}