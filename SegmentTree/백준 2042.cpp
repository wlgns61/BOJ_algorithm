#include <iostream>
#include <vector>
#include <cmath>
#define ll long long

using namespace std;

ll make_tree(vector <ll> &arr, vector <ll> &tree, ll start, ll end, ll node) {
	
	if (start == end)
		return tree[node] = arr[start];
	ll mid = (start + end) / 2;
	return tree[node] = make_tree(arr, tree, start, mid, node * 2) + 
		make_tree(arr, tree, mid + 1, end, node * 2 + 1);
}

void update(vector <ll> &tree, int start, int end, ll node, ll idx, ll diff) { //diff는 원래 값과의 차이이다.
	
	if (!(start <= idx && idx <= end))
		return;
	tree[node] += diff;
	if (start != end) {
		ll mid = (start + end) / 2;
		update(tree, start, mid, node * 2, idx, diff);
		update(tree, mid + 1, end, node * 2 + 1, idx, diff);
	}
}

ll partial_sum(vector <ll> &tree, int start, int end, ll node, int left, int right) {
	
	if (right < start || end < left)  //합을 구하고자 하는 구간이 완전히 벗어나는 경우 
		return 0;
	if (left <= start && end <= right) // 합을 구하고자 하는 구간이 트리의 구간을 포함하는 경우  
		return tree[node];
	int mid = (start + end) / 2;
	return partial_sum(tree, start, mid, node * 2, left, right) + 
		partial_sum(tree, mid + 1, end, node * 2 + 1, left, right);
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;

	int length = int(ceil(log2(n))) + 1;
	length = (1 << length);

	vector <ll> arr(n + 1, 0);
	vector <ll> tree(4*n, 0);

	for (int i = 0; i < n; i++) {
		ll num;
		cin >> num;
		arr[i + 1] = num;
	}
	make_tree(arr, tree, 1, n, 1);
	while (m > 0 || k > 0) {
		ll query, a, b;
		cin >> query >> a >> b;
		if (query == 1) {
			ll diff = b - arr[a]; //이 부분을 위해
			arr[a] = b;
			update(tree, 1, n, 1, a, diff);
			m--;
		}
		else if (query == 2) {
			cout << partial_sum(tree, 1, n, 1, a, b) << "\n";
			k--;
		}
	}

}