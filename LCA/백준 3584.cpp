#include <iostream>
#include <cstdio>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

vector <int> tree[10001];
int parent[10001];
int dp[10001][16];
int depth[10001];

int LCA(int x, int y) {
	if (depth[x] != depth[y]) { //���� ���̷� �̵�
		if (depth[x] > depth[y]) //x�� ���̰� ��ٸ�
			swap(x, y);  //x�� ���̰� �� ����, �� �� ���� ��
		for (int i = 15; i >= 0; i--) {
			if (depth[y] - depth[x] >= (1 << i)) { //2^i
				y = dp[y][i]; //�� ���� ���̺��� �ö��� �ʴ� �ѿ� y�� �������� ������Ʈ
			}
		}
	}
	if (x == y) return x; // ���� ���� ���� ������

	if (x != y) { //���� �����ε� ���� �ٸ��ٸ�
		for (int i = 15; i >= 0; i--) {
			if (dp[x][i] != dp[y][i]) { //������ ���� �޶����� �������� 
				x = dp[x][i];         // i�� ����
				y = dp[y][i];
			}
		}
	}
	return dp[x][0]; //���� ���ǿ��� �θ�� ���� ������ ����
	//�޶� ���� ���� �������� �ٷ� �ڽ��� �θ��尡 ��������
}

void dfs(int now, int dep, int par) { //root�� ��Ȯ�� � ������ �˼��� ���� ������ root�� �������� Ž����
	depth[now] = dep;
	for (int i = 0; i < tree[now].size(); i++) {
		int next = tree[now][i];
		if (next == par)
			continue;
		dp[next][0] = now;  //2^0 = 1�̹Ƿ� �ٷ����� �θ�
		dfs(next, dep + 1, now);
	}
}

void init_dp(int N) {
	for (int y = 1; y <= 15; y++) { //DP �迭 ����
		for (int x = 1; x <= N; x++) {
			int ancestor = dp[x][y - 1];
			dp[x][y] = dp[ancestor][y - 1];
		}
	}
}

int find_root(int a) {
	if (parent[a] == 0)
		return a;
	return find_root(parent[a]);
}

int main() {
	int T;
	scanf("%d", &T);
	while (--T >= 0) {
		int N;
		scanf("%d", &N);
		for (int i = 0; i < 10001; i++)
			tree[i].clear();
		for (int i = 0; i < 16; i++) {
			memset(dp[i], 0, 10001);
		}
		memset(depth, 0, 10001);
		memset(parent, 0, 10001);
		for (int i = 0; i < N - 1; i++) {
			int A, B;
			scanf("%d %d", &A, &B);
			tree[A].push_back(B); // ������� ����ϴ� ������ dfsŽ���� ��Ʈ���� �ڽ� �������� ��������
			tree[B].push_back(A); // �ּҰ��������� ã�� ���ؼ��� �ڽĿ��� �θ� �������� ���ϱ� �����̴�.
			parent[B] = A;
		}
		int x, y;
		scanf("%d %d", &x, &y);
		int root = find_root(1);
		dfs(root, 0, root); //��Ʈ�� 0���� ����
		init_dp(N);
		printf("%d\n", LCA(x, y));
	}
}