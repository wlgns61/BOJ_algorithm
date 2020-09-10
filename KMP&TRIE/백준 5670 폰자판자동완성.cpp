#include <iostream>
#include <string>
#include <map>
#include <queue>

using namespace std;

typedef struct trie {
	map <char, trie> child;
};

void insert(trie &node, string &word, int idx) {
	if (word.size() == idx)
		return;
	if (node.child.count(word[idx]) == 0) {
		node.child[word[idx]] = trie();
	}
	insert(node.child[word[idx]], word, idx + 1);
}

float bfs(trie &node) {

	queue <pair<trie, int>> q;
	int sum = 0;
	int cnt = 0;
	for (const auto& i : node.child) {
		cnt++;
		if (cnt > 1) break;
	}
	if (cnt <= 1) 
		q.push({ node, 1 });
	else 
		q.push({ node, 0 });

	while (!q.empty()) {
		trie now = q.front().first;
		int now_cnt = q.front().second;
		q.pop();
		int child_num = 0;
		for (const auto& i : now.child) {
			child_num++;
			if (child_num > 1)
				break;
		}
		for (const auto& i : now.child) {
			if (i.first == '.') 
				sum += now_cnt;
			else if (child_num <= 1)
				q.push({ i.second, now_cnt});
			else if (child_num > 1)
				q.push({ i.second, now_cnt + 1 });
		}
	}
	return sum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	while (cin >> t) {
		trie root;
		for (int i = 0; i < t; i++) {
			string word;
			cin >> word;
			insert(root, word.append("."), 0);
		}
		cout << fixed;
		cout.precision(2);
		cout << bfs(root)/t << "\n";
	}
}