//새그먼트트리의 최소 최대와 빌리는 비디오의 최소 최대를 비교
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAX 123456789

using namespace std;

int makeMaxTree(vector <int> &tree, vector <int> &arr, int start, int end, int node) {

	if (start == end)
		return tree[node] = arr[start];
	int mid = (start + end) / 2;
	return tree[node] = max(makeMaxTree(tree, arr, start, mid, node * 2), 
		makeMaxTree(tree, arr, mid + 1, end, node * 2 + 1));
}

int makeMinTree(vector <int> &tree, vector <int> &arr, int start, int end, int node) {

	if (start == end)
		return tree[node] = arr[start];
	int mid = (start + end) / 2;
	return tree[node] = min(makeMinTree(tree, arr, start, mid, node * 2),
		makeMinTree(tree, arr, mid + 1, end, node * 2 + 1));
}

int updateMax(vector <int> &tree, int start, int end, int node, int pos, int val) { //왠지 바텀업으로 해결해야 할 거 같음
	
	if (!(start <= pos && pos <= end))
		return tree[node];
	if (start == end)
		return tree[node] = val;
	int mid = (start + end) / 2;
	return tree[node] = max(updateMax(tree, start, mid, node * 2, pos, val),
		updateMax(tree, mid + 1, end, node * 2 + 1, pos, val));
}

int updateMin(vector <int> &tree, int start, int end, int node, int pos, int val) { 

	if (!(start <= pos && pos <= end))
		return tree[node];
	if (start == end)
		return tree[node] = val;
	int mid = (start + end) / 2;
	return tree[node] = min(updateMin(tree, start, mid, node * 2, pos, val),
		updateMin(tree, mid + 1, end, node * 2 + 1, pos, val));
}

int findMax(vector <int> &tree, int start, int end, int node, int left, int right) {
	if (right < start || end < left) 
		return 0;
	if (left <= start && end <= right)
		return tree[node];
	int mid = (start + end) / 2;
	return max(findMax(tree, start, mid, node * 2, left, right),
		findMax(tree, mid + 1, end, node * 2 + 1, left, right));
}

int findMin(vector <int> &tree, int start, int end, int node, int left, int right) {
	if (right < start || end < left)
		return MAX;
	if (left <= start && end <= right)
		return tree[node];
	int mid = (start + end) / 2;
	return min(findMin(tree, start, mid, node * 2, left, right),
		findMin(tree, mid + 1, end, node * 2 + 1, left, right));
}

void solve() {
	
	int n, k;
	cin >> n >> k;
	
	int length = int(ceil(log2(n))) + 1;
	length = (1 << length);

	vector <int> arr(n+1, 0);
	vector <int> maxtree(length, 0);
	vector <int> mintree(length, MAX);

	for (int i = 0; i < arr.size() - 1; i++) {
		arr[i+1] = i+1;
	}

	makeMaxTree(maxtree, arr, 1, n, 1);
	makeMinTree(mintree, arr, 1, n, 1);

	for (int i = 0; i < k; i++) {
		int q, a, b;
		cin >> q >> a >> b;
		a++; b++;
		if (q) {
			int max_ = findMax(maxtree, 1, n, 1, a, b);
			int min_ = findMin(mintree, 1, n, 1, a, b);
			if (min_ == a && max_ == b)
				cout << "YES\n";
			else
				cout << "NO\n";
		}
		else { //arr의 변화가 생기는 경우 
			swap(arr[a], arr[b]);
			updateMax(maxtree, 1, n, 1, a, arr[a]);
			updateMax(maxtree, 1, n, 1, b, arr[b]);
			updateMin(mintree, 1, n, 1, a, arr[a]);
			updateMin(mintree, 1, n, 1, b, arr[b]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (--t >= 0) {
		solve();
	}
}