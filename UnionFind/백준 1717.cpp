#include <iostream>
#include <stdio.h>

using namespace std;
int tree[1000002];

int find(int a) { //��Ʈ�� ��ȯ
	if (tree[a] == a) { //�ڱ� �ڽ��� ��Ʈ�̸�
		return a;
	}
	int root = find(tree[a]);
	tree[a] = root;
	return root;
}

void Union(int a, int b) { //a�� ��Ʈ�� �����ϰ� Ǯ����
	a = find(a);
	b = find(b);
	tree[b] = a;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i <= n; i++) {
		tree[i] = i; //�ڱ� �ڽ��� ��Ʈ
	}
	for (int i = 0; i < m; i++) {
		int inst, a, b;
		scanf("%d %d %d", &inst, &a, &b);
		if (inst == 0) {
			Union(a, b);
		}
		else {
			if (find(a) == find(b)) 
				printf("YES\n");
			else
				printf("NO\n");
		}
	}

}