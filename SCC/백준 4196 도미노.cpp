#include <iostream>
#include <vector>
#include <string.h>
#include <stack>

using namespace std;

void dfs(int now, vector <bool> &visited, vector <vector<int>> &graph, stack <int> &st) {
	visited[now] = true;
	for (int i = 0; i < graph[now].size(); i++) {
		int next = graph[now][i];
		if (visited[next] == false) {
			dfs(next, visited, graph, st);
		}
	}
	st.push(now);
}

void rev_dfs(int now, vector <vector<int>> &graph, int scc_num, vector <int> &scc, vector <vector<int>> &scc_info) {

	scc[now] = scc_num;
	scc_info.back().push_back(now);
	for (int i = 0; i < graph[now].size(); i++) {
		int next = graph[now][i];
		if (!scc[next]) {
			rev_dfs(next, graph, scc_num, scc, scc_info);
		}
	}
}


int main() {
	int t;
	scanf("%d", &t);
	while (--t >= 0) {
		int n, m;
		int cnt = 0;
		scanf("%d %d", &n, &m);
		stack <int> st;
		vector <bool> visited(100001, false);
		vector <int> scc(100001, 0);
		vector <vector<int>> graph(100001);
		vector <vector<int>> rev(100001);
		vector <vector<int>> scc_info;
		for (int i = 0; i < m; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			graph[a].push_back(b);
			rev[b].push_back(a);
		}
		for (int i = 1; i <= n; i++) {
			if (visited[i] == false) 
				dfs(i, visited, graph, st);
		}
		int scc_num = 0;
		while (!st.empty()) {
			int top = st.top();
			st.pop();
			if (scc[top] != 0)
				continue;
			scc_info.push_back(vector<int>());
			rev_dfs(top, rev, ++scc_num, scc, scc_info);
		}
		int ans = 0;
		for (auto &i : scc_info) {
			bool flag = 1;
			for (auto &j : i) {
				for (auto &k : rev[j]) {
					if (scc[j] == scc[k])
						continue;
					flag = 0; //하나의 scc집합안에 집합 밖의 어떠한 요소가 집합으로 향하는 경우, scc집합은 안 건드려도 알아서 쓰러짐
				}
			}
			ans += flag;
		}
		cout << ans << "\n";
	}
}