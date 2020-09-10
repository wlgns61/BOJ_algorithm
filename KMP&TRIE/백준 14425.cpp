#include <iostream>
#include <string>
#include <map>

using namespace std;

typedef struct Node {
	map <char, Node> child;
};
Node root;
int result = 0;

void insert(Node &node, string &word, int idx) {
	if (word.size() == idx) return;
	if (node.child.count(word[idx]) == 0) {
		node.child[word[idx]] = Node();
	}
	insert(node.child[word[idx]], word, idx + 1);
}

void find(Node &node, string &word, int idx) {
	if (word.size() - 1 == idx) {
		if (node.child.count(word[idx]) != 0) {
			result++;
			return;
		}
	}
	if (node.child.count(word[idx]) != 0) { //존재한다면
		find(node.child[word[idx]], word, idx + 1);
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string word;
		cin >> word;
		insert(root, word.append("."), 0);
	}
	for (int i = 0; i < m; i++) {
		string word;
		cin >> word;
		find(root, word.append("."), 0);
	}
	cout << result;
}