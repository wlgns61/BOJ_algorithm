#include <iostream>
#include <vector>

using namespace std;
int inorder[100001];
int postorder[100001];
int position[100001];

void preorder(int in_start, int in_end, int post_start, int post_end) {

	if (in_start > in_end || post_start > post_end) return;

	int root = postorder[post_end];
	cout << root << " ";
	int left = position[root] - in_start;
	preorder(in_start, position[root] - 1, post_start, post_start + left - 1);
	preorder(position[root] + 1, in_end, post_start + left, post_end - 1);
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) 
		cin >> inorder[i];
	for (int i = 0; i < n; i++)
		cin >> postorder[i];
	for (int i = 0; i < n; i++) {
		position[inorder[i]] = i;
	}
	preorder(0, n - 1, 0, n - 1);
}