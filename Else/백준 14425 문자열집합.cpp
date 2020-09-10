#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

typedef struct Trie {
	map<char, Trie> child;
	bool data;
};

int n, m;
int cnt = 0;
Trie trie;

void insert(Trie &node, string &word, int idx) {
	if (idx == word.size()) {
		node.data = true;
		return;
	}
	if (node.child.count(word[idx]) == 0) {
		node.child[word[idx]] = Trie();
		node.child[word[idx]].data = false;
	}
	insert(node.child[word[idx]], word, idx + 1);
}

bool findWord(Trie &node, string &word, int idx) {
	if (idx == word.size() && node.data == true) {
		return true;
	}
	if (node.child.count(word[idx]) == 0) {
		return false;
	}
	return findWord(node.child[word[idx]], word, idx + 1);
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		string word;
		cin >> word;
		insert(trie, word, 0);
	}
	for (int i = 0; i < m; i++) {
		string word;
		cin >> word;
		if (findWord(trie, word, 0)) {
			//cout << "find: " << word << endl;
			cnt++;
		}
	}
	cout << cnt;
}