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
	if (depth[x] != depth[y]) { //같은 깊이로 이동
		if (depth[x] > depth[y]) //x의 깊이가 깊다면
			swap(x, y);  //x의 깊이가 더 얕음, 즉 더 작은 수
		for (int i = 15; i >= 0; i--) {
			if (depth[y] - depth[x] >= (1 << i)) { //2^i
				y = dp[y][i]; //더 얕은 깊이보다 올라가지 않는 한에 y의 조상으로 업데이트
			}
		}
	}
	if (x == y) return x; // 같은 깊이 까지 왔을때

	if (x != y) { //같은 깊이인데 서로 다르다면
		for (int i = 15; i >= 0; i--) {
			if (dp[x][i] != dp[y][i]) { //조상이 서로 달라지는 순간까지 
				x = dp[x][i];         // i가 감소
				y = dp[y][i];
			}
		}
	}
	return dp[x][0]; //위의 조건에서 부모는 같고 서로의 값이
	//달라 질때 까지 왔음으로 바로 자신의 부모노드가 공통조상
}

void dfs(int now, int dep, int par) { //root가 정확히 어떤 값인지 알수는 없음 하지만 root를 가지도록 탐색함
	depth[now] = dep;
	for (int i = 0; i < tree[now].size(); i++) {
		int next = tree[now][i];
		if (next == par)
			continue;
		dp[next][0] = now;  //2^0 = 1이므로 바로위의 부모
		dfs(next, dep + 1, now);
	}
}

void init_dp(int N) {
	for (int y = 1; y <= 15; y++) { //DP 배열 생성
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
			tree[A].push_back(B); // 양방향을 사용하는 이유는 dfs탐색시 루트에서 자식 방향으로 향하지만
			tree[B].push_back(A); // 최소공통조상을 찾기 위해서는 자식에서 부모 방향으로 향하기 때문이다.
			parent[B] = A;
		}
		int x, y;
		scanf("%d %d", &x, &y);
		int root = find_root(1);
		dfs(root, 0, root); //루트를 0으로 지정
		init_dp(N);
		printf("%d\n", LCA(x, y));
	}
}