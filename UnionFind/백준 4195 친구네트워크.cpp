#include <iostream>
#include <map>
#include <string>
#include <cstring>
#include <stdio.h>

using namespace std;
int tree[100010];
int cnt[100010];

int find(int a) { //��Ʈ�� ��ȯ
	if (tree[a] == -1 || tree[a] == a) { //�ڱ� �ڽ��� ��Ʈ�̸�
		return a;
	}
	int root = find(tree[a]);
	tree[a] = root;
	return root;
}

void Union(int a, int b) { //a�� ��Ʈ�� �����ϰ� Ǯ����
	a = find(a);
	b = find(b);
	if(a != b)
		cnt[a] += cnt[b];
	tree[b] = a;
	cout << cnt[a] << "\n";
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T , F;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> F;
		map <string, int> name;
		memset(tree, -1, sizeof(tree));
		fill_n(cnt, 100010, 1);
		int idx = 1;
		for (int j = 0; j < F; j++) {
			string name1, name2;
			cin >> name1 >> name2;
			if (name.count(name1) == 0) {
				name[name1] = idx++;
			}
			if (name.count(name2) == 0) {
				name[name2] = idx++;
			}
			//m[key] = value �̰� �߿�
			Union(name[name1], name[name2]);
		}
	}
}