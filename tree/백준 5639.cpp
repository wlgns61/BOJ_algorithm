#include <iostream>
#include <algorithm>

using namespace std;

int tree[10002];

void postorder(const int& left, const int& right) {
	if (left > right) return;
	int root = tree[left];
	int mid = right;
	while (root < tree[mid]) mid--;
	postorder(left + 1, mid);
	postorder(mid + 1, right);
	printf("%d\n", root);
}

int main() {
	int n;
	int i = 0;
	while (scanf("%d", &n) != -1) tree[i++] = n;
	postorder(0, i - 1);	
	return 0;
}