#include <iostream>
#include <stdio.h>

using namespace std;
int map[201];

int find(int a) {  //�� ����� �θ� ��Ʈ�� ����� �ְ� ��Ʈ ��ȯ
	if (map[a] == a) { //�ڽ��� ��Ʈ�϶�
		return a;
	}
	int root = find(map[a]);
	map[a] = root;
	return root;
}

void Union(int a, int b) {
	a = find(a);
	b = find(b);
	map[b] = a; 
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i <= n; i++) {
		map[i] = i; //�ڱ� �ڽ��� ��Ʈ
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int connect;
			scanf("%d", &connect);
			if (connect == 1)
				Union(i, j);
		}
	}
	int city;
	scanf("%d", &city);
	int now = find(city);
	for (int i = 1; i < m; i++) {
		scanf("%d", &city);
		if (now != find(city)) {
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");

}