#include <iostream>
#include <stdio.h>

using namespace std;

class Tree;

class TreeNode {
	friend class Tree;
private:
	int data;
	TreeNode *left;
	TreeNode *right;
public:
	TreeNode(int data = 0, TreeNode *left = NULL, TreeNode *right = NULL) { //»ý¼ºÀÚ 
		this->data = data;
		this->left = left;
		this->right = right;
	}
};

class Tree {
private:
	TreeNode *root;
public:
	void init(int data) {
		root = new TreeNode(data);
	}
	void insert(int data) {
		TreeNode *newnode = new TreeNode(data);
		TreeNode *current = root;
		while (true) {
			if (data > current->data) {
				if (current->right == NULL) {
					current->right = newnode;
					break;
				}
				else {
					current = current->right;
				}
			}
			else if (data < current->data) {
				if (current->left == NULL) {
					current->left = newnode;
					break;
				}
				else {
					current = current->left;
				}
			}
		}
	}
	int search(int data) {
		TreeNode *current = root;
		while (current != NULL) {
			if (data > current->data) {
				current = current->right;
			}
			else if (data < current->data) {
				current = current->left;
			}
			else if (data == current->data) {
				return 1;
			}
		}
		return 0;
	}
	
};

int main() {
	int N, M;
	scanf("%d", &N);
	Tree tree;
	for (int i = 0; i < N; i++) {
		int num;
		scanf("%d", &num);
		if (i == 0) {
			tree.init(num);
		}
		else {
			tree.insert(num);
		}
	}
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int num;
		scanf("%d", &num);
		printf("%d\n", tree.search(num));
	}
}