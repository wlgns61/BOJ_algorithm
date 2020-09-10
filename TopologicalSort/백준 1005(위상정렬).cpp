#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while (--t >= 0) {
		int N, K;
		scanf("%d %d", &N, &K);

		vector <int> from_to[1002];
		int building[1002] = { 0 };
		int indegree[1002] = { 0 };
		int time[1002] = { 0 };

		for (int i = 1; i <= N; i++)
			scanf("%d", &building[i]);
		for (int i = 1; i <= K; i++) {
			int from, to;
			scanf("%d %d", &from, &to);
			from_to[from].push_back(to);
			indegree[to]++;
		}
		int last;
		scanf("%d", &last);
		
		//루프의 입력 완료
		queue <int> q;
		for (int i = 1; i <= N; i++) {
			if (indegree[i] == 0) {
				q.push(i);
				time[i] = building[i];
			}
				
		}
		while (!q.empty()) {
			int now = q.front();
			q.pop();
			if (now == last) break;
			for (int i = 0; i < from_to[now].size(); i++){
				int next = from_to[now][i];
				if (--indegree[next] == 0)
					q.push(next);
				if (time[next] < time[now] + building[next])
					time[next] = time[now] + building[next];
			}
		}
		printf("%d\n", time[last]);
	}
}