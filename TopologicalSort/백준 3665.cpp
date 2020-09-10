#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while (--t >= 0) {
		int n, m;
		scanf("%d", &n);
		int table[501][501] = {0};
		int indegree[501] = {0};
		int temp[501] = {0};
		for (int i = 0; i < n; i++) 
			scanf("%d", &temp[i]);
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n;j++) {
				table[temp[i]][temp[j]] = 1; //[출발][도착]
				indegree[temp[j]]++;
			}
		}
		scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			if (table[a][b] == 1) {
				table[a][b] = 0;
				table[b][a] = 1;
				indegree[a]++;
				indegree[b]--;
			}
			else if (table[b][a] == 1) {
				table[b][a] = 0;
				table[a][b] = 1;
				indegree[a]--;
				indegree[b]++;
			}
		}
		//여기 까지 입력 완료
		queue <int> q;
		for (int i = 1; i <= n; i++) {
			if (indegree[i] == 0)
				q.push(i);
		}

		bool possible = true;
		vector <int> ans;
		while (!q.empty()) {
			if (q.size() > 1) {
				possible = false;
				break;
			}
			int now = q.front();
			q.pop();
			ans.push_back(now);
			for (int next = 1; next <= n; next++) {
				if (table[now][next] == 1) 
					if (--indegree[next] == 0) 
						q.push(next);
			}
		}
		if (!possible) {
			printf("?\n");
		}
		else if (ans.size() == n) {
			for (int i = 0; i < n; i++) {
				printf("%d ", ans[i]);
			}
			printf("\n");
		}
		else {
			printf("IMPOSSIBLE\n");
		}
	}
}