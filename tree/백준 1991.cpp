//트리 순회
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

vector <pair<int, int>> tree(27);
int visited[27];


void preorder(int start) {
	cout << char(start + int('A'));
	if(tree[start].first != -1)		
		preorder(tree[start].first);
	if(tree[start].second != -1)
		preorder(tree[start].second);
}

void inorder(int start) {
	if (tree[start].first != -1)
		inorder(tree[start].first);
	cout << char(start + int('A'));
	if (tree[start].second != -1)
		inorder(tree[start].second);
}

void postorder(int start) {
	if (tree[start].first != -1)
		postorder(tree[start].first);
	if (tree[start].second != -1)
		postorder(tree[start].second);
	cout << char(start + int('A'));
}

int main() {
	int V;
	cin >> V;
	for (int i = 0; i < V; i++) {
		char parent, left, right;
		cin >> parent >> left >> right;
		tree[int(parent) - int('A')] = { int(left) - int('A') ,int(right) - int('A') };
		if (left == '.') {
			tree[int(parent) - int('A')].first = -1;
		}
		if (right == '.') {
			tree[int(parent) - int('A')].second = -1;
		}
	}
	preorder(0);
	cout << "\n";
	inorder(0);
	cout << "\n";
	postorder(0);
}