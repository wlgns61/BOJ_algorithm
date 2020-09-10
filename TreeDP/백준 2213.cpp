#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cost[10002];
int check[10002];
int dp[10002][2];
vector <int> tree[10002];
vector <int> adj[10002];
vector <int> result;

void dfs(int here, int parent) {
	for (int i = 0; i < adj[here].size(); i++) {
		int next = adj[here][i];
		if (next != parent) {  //��尡 ��������� �����ϱ� ������ Ž�� �� �θ� ������ �ö󰡴� ���� ������ 
			tree[here].push_back(next);
			dfs(next, here);
		}
	}
}

int solve(int now, int include) {
	int &res = dp[now][include];
	if (res != -1) return res; // �湮������ �ִٸ�(�ֳĸ� �̹� �ִ��� ���������� �ֱ� ������ ����� �ߺ��� ���� ����)
	if (include) {
		int ans = 0;
		for (int i = 0; i < tree[now].size(); i++) {
			int next = tree[now][i];
			ans += solve(next, 0); //���� �ڽĵ�� ����� ����� �������� �ؼ�
		}
		return res = ans + cost[now];
	}
	else {
		int ans = 0;
		for (int i = 0; i < tree[now].size(); i++) {
			int next = tree[now][i];
			int t1 = solve(next, 1);
			int t2 = solve(next, 0);
			if (t1 > t2) 
				check[next] = 1;
			else 
				check[next] = 0;
			ans += max(t1, t2); //���� �ڽĵ�� ����� ����� �������� �ؼ�
		}
		return res = ans;
	}
	
}

void track(int now, int include) {
	if (include) {
		result.push_back(now);
		for (int i = 0; i < tree[now].size(); i++) {
			int next = tree[now][i];
			track(next, 0);
		}
	}
	else {
		for (int i = 0; i < tree[now].size(); i++) {
			int next = tree[now][i];
			track(next, check[next]);
		}
	}

}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &cost[i]);
		dp[i][0] = dp[i][1] = -1;
	}
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1, 1); //��Ʈ�� 1�� ���
	int t1 = solve(1, 1);
	int t2 = solve(1, 0);
	if (t1 > t2)
		check[1] = 1;
	int max_ = max(t1, t2);
	printf("%d\n", max_);
	track(1, check[1]);
	sort(result.begin(), result.end());
	for (int i = 0; i < result.size(); i++) {
		printf("%d ", result[i]);
	}
	
}