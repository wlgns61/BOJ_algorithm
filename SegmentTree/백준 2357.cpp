#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAX 1000000001

using namespace std;

int max_tree(vector <pair<int, int>> &tree, vector <int> &arr, int start, int end, int node) {

	if (start == end) {
		return tree[node].first = arr[start];
	}
	int mid = (start + end) / 2;
	return tree[node].first = max(max_tree(tree, arr, start, mid, node * 2), 
		max_tree(tree, arr, mid + 1, end, node * 2 + 1));
}

int min_tree(vector <pair<int, int>> &tree, vector <int> &arr, int start, int end, int node) {

	if (start == end) {
		return tree[node].second = arr[start];
	}
	int mid = (start + end) / 2;
	return tree[node].second = min(min_tree(tree, arr, start, mid, node * 2),
		min_tree(tree, arr, mid + 1, end, node * 2 + 1));
}

int find_max(vector <pair<int, int>> &tree, int start, int end, int node, int left, int right) {

	if (right < start || end < left)
		return 0;
	if (left <= start && end <= right)
		return tree[node].first;
	int mid = (start + end) / 2;
	return max(find_max(tree, start, mid, node * 2, left, right),
		find_max(tree, mid + 1, end, node * 2 + 1, left, right));
}

int find_min(vector <pair<int, int>> &tree, int start, int end, int node, int left, int right) {

	if (right < start || end < left)
		return MAX;
	if (left <= start && end <= right)
		return tree[node].second;
	int mid = (start + end) / 2;
	return min(find_min(tree, start, mid, node * 2, left, right),
		find_min(tree, mid + 1, end, node * 2 + 1, left, right));
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	int length = int(ceil(log2(n))) + 1;
	length = (1 << length);

	vector <int> arr(n + 1, 0);
	vector <pair<int, int>> tree(length, {0, MAX}); //최대 최소

	for (int i = 0; i < n; i++) 
		cin >> arr[i + 1];
	max_tree(tree, arr, 1, n, 1);
	min_tree(tree, arr, 1, n, 1);
	
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout << find_min(tree, 1, n, 1, a, b)<< " " << find_max(tree, 1, n, 1, a, b)<< "\n";
	}

}