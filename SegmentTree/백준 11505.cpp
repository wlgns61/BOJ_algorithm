#include <iostream>
#include <vector>
#include <cmath>
#define ll long long
#define DIV 1000000007 

using namespace std;

ll init_tree(vector <ll> &arr, vector <ll> &tree, int start, int end, int node) {

	if (start == end)
		return tree[node] = arr[start];
	int mid = (start + end) / 2;
	return tree[node] = (((init_tree(arr, tree, start, mid, node * 2) % DIV)
		* (init_tree(arr, tree, mid + 1, end, node * 2 + 1) % DIV))) % DIV;
}

ll update(vector <ll> &tree, int start, int end, int node, int idx, ll val) { //바텀업 방식을 사용하면 리프부터 업데이트 가능

	if (!(start <= idx && idx <= end))
		return tree[node];
	if (start == end) //리프에 도달
		return tree[node] = val;
	int mid = (start + end) / 2;
	return tree[node] = ((update(tree, start, mid, node * 2, idx, val) % DIV)
		* (update(tree, mid + 1, end, node * 2 + 1, idx, val) % DIV)) % DIV;
}

ll partial_mul(vector <ll> &tree, int start, int end, int node, int left, int right) { 

	if (right < start || end < left)
		return 1;
	if (left <= start && end <= right)
		return tree[node];
	int mid = (start + end) / 2;
	return (((partial_mul(tree, start, mid, node * 2, left, right) % DIV) *
		(partial_mul(tree, mid + 1, end, node * 2 + 1, left, right) % DIV)))% DIV;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;

	int length = int(ceil(log2(n))) + 1;
	length = (1 << length);

	vector < ll > arr(n + 1,0);
	vector < ll > tree(length, 0);

	for (int i = 0; i < n; i++) {
		ll num;
		cin >> num;
		arr[i + 1] = num;
	}
	init_tree(arr, tree, 1, n, 1);

	ll query, a, b;
	while (m > 0 || k > 0) {
		cin >> query >> a >> b;
		if (query == 1) {
			update(tree, 1, n, 1, a, b);
			arr[a] = b;
			m--;
		}
		else if (query == 2) {
			cout << partial_mul(tree, 1, n, 1, a, b) << "\n";
			k--;
		}
	}
}