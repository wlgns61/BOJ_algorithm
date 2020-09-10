#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;
vector<int> ranking;
int map[501][501];
int indegree[501];
int t, n, m;

void preprocessing() {
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			map[ranking[i]][ranking[j]] = 1;
			indegree[ranking[j]]++;
		}
	}
}

void change(int i, int j) {
	if (map[i][j]) { // 비정상적 변환
		map[i][j] = 0;
		indegree[j]--;
		map[j][i] = 1;
		indegree[i]++;
	}
	else if (map[j][i]) { //정상적인 변환
		map[j][i] = 0;
		indegree[i]--;
		map[i][j] = 1;
		indegree[j]++;
	}
}


int main() {

	cin >> t;

	while (--t >= 0) {

		ranking.clear();
		memset(map, 0, sizeof(map));
		memset(indegree, 0, sizeof(indegree));

		cin >> n;
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			ranking.push_back(num);
		}
		preprocessing();

		cin >> m;
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			change(a, b);
		}

		queue<int> q;
		for (int i = 1; i <= n; i++) {
			if (indegree[i] == 0)
				q.push(i);
		}

		vector <int> ans;
		while (!q.empty()) {
			int now = q.front();
			q.pop();
			ans.push_back(now);
			for (int i = 0; i < n; i++) {
				if (map[now][i]) {
					if (--indegree[i] == 0) {
						q.push(i);
					}
				}
			}
		}
	}
}