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

float search(trie &node, string &word, int idx) {

	if (word[idx] == '.') {
		return 0;
	}
	if (node.child.size() > 1) {
		return search(node.child[word[idx]], word, idx + 1) + 1; 
	}
	else {
		return search(node.child[word[idx]], word, idx + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	while (cin >> t) {
		trie root;
		vector<string> dict;
		float res = 0;
		for (int i = 0; i < t; i++) {
			string word;
			cin >> word;
			dict.push_back(word.append("."));
			insert(root, word.append("."), 0);
		}
		for (int i = 0; i < t; i++) {
			res += search(root, dict[i], 0);
		}
		cout << fixed;
		cout.precision(2);
		if (root.child.size() == 1)
			cout << (res / t) + 1 << "\n";
		else
			cout << res / t << "\n";
	}
}