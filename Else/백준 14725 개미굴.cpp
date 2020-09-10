#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

typedef struct trie {
	map<string, trie> child;
};

trie cave;

void insert(trie &node, vector<string> &food, int idx) {
	if (idx == food.size()) {
		return;
	}
	if (node.child.count(food[idx]) == 0) { // 없다면
		node.child[food[idx]] = trie(); //트라이 할당
	}
	insert(node.child[food[idx]], food, idx + 1);
}

void dfs(trie &node, int depth) {
	for (pair<string, trie> i : node.child) {
		for (int j = 0; j < depth; j++) {
			cout << "--";
		}
		cout << i.first << "\n";
		dfs(i.second, depth + 1);
	}
}

int main() {

	int n;

	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		vector<string> foods;
		for (int j = 0; j < num; j++) {
			string food;
			cin >> food;
			foods.push_back(food);
		}
		insert(cave, foods, 0);
	}
	dfs(cave, 0);
}