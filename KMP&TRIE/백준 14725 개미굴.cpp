#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

using namespace std;

typedef struct Node {
	map <string, Node> child;
};
Node root;


void insert(Node &node, vector<string> &arr, int idx) {
	if (idx == arr.size())
		return;
	if (node.child.count(arr[idx]) == 0) {
		node.child[arr[idx]] = Node();
	}
	insert(node.child[arr[idx]], arr, idx + 1);
}

void dfs(Node &v, int depth) {
	for (pair<string, Node> i : v.child) { //사전순으로 반환
		for (int j = 0; j < depth; j++) {
			cout << "--";
		}
		cout << i.first << "\n";
		dfs(i.second, depth + 1);
	}
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		vector <string> v;
		for (int j = 0; j < n; j++) {
			string food;
			cin >> food;
			v.push_back(food);
		}
		insert(root, v, 0);
	}
	dfs(root, 0);
}