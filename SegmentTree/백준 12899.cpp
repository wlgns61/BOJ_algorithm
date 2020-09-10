#include <iostream>
#include <vector>
#include <cmath>
#define SIZE 2000005

using namespace std;

void update(vector <int> &tree, int start, int end, int node, int idx, int val) {
	
	if (idx < start || end < idx)
		return;
	if (start == end) {
		tree[node] += val;
		return;
	}
	int mid = (start + end) / 2;
	update(tree, start, mid, node * 2, idx, val);
	update(tree, mid + 1, end, node * 2 + 1, idx, val);
	tree[node] = tree[node * 2] + tree[node * 2 + 1]; //트리의 노드의 저장값은 해당 노드의 start~end범위의 수가 몇개 있는지 count
}

int find_idx(vector <int> &tree, int start, int end, int node, int idx) {
	if (start == end)
		return start;
	else {
		int mid = (start + end) / 2;
		if (idx <= tree[node * 2])
			return find_idx(tree, start, mid, node * 2, idx);
		else
			return find_idx(tree, mid + 1, end, node * 2 + 1, idx - tree[node * 2]);
	}
}



int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int length = int(ceil(log2(SIZE))) + 1;
	length = (1 << length);
	vector <int> tree(length, 0);

	for (int i = 0; i < n; i++) {
		int q, num;
		cin >> q >> num;
		if (q == 1) {
			update(tree, 1, SIZE, 1, num, 1);
		}
		else {
			int res = find_idx(tree, 1, SIZE, 1, num);
			cout << res << "\n";
			update(tree, 1, SIZE, 1, res, -1);
		}
	}
}