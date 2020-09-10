//축구전술 : scc중 indegree가 0인 것이 단 하나여야 한다. 
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

void dfs(int now, vector <bool> &visited, stack <int> &st, vector <vector<int>> &v) { //사이클이 존재 가능 하므로 visited로 체크를 해주어야 함

	visited[now] = true;
	for (int i = 0; i < v[now].size(); i++) {
		int next = v[now][i];
		if(visited[next] == false)
			dfs(next, visited, st, v);
	}
	st.push(now);
}

void rev_dfs(int now, int color, vector <vector<int>> &v, vector <int> &SCC, vector <vector<int>> &scc_info) {

	SCC[now] = color;
	scc_info.back().push_back(now);
	for (int i = 0; i < v[now].size(); i++) {
		int next = v[now][i];
		if (!SCC[next]) {
			rev_dfs(next, color, v, SCC, scc_info);
		}
	}

}

void solve() {

	int n, m;
	cin >> n >> m;
	vector <vector<int>> graph(100001);
	vector <vector<int>> rev(100001);
	vector <vector<int>> scc_info;
	vector <bool> visited(100001, false);
	vector <int> SCC(100001, 0);
	vector <int> indegree(100001, 0);
	stack <int> st;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		rev[b].push_back(a);
	}
	for (int i = 0; i < n; i++) {
		if(visited[i] == false)
			dfs(i, visited, st, graph);
	}
	int scc_num = 0;
	while (!st.empty()) {
		int top = st.top();
		st.pop();
		if (SCC[top] != 0)
			continue;
		scc_info.push_back(vector<int>());
		rev_dfs(top, ++scc_num, rev, SCC, scc_info);
	}
	for (int i = 0; i < n; i++) {
		for (auto j : graph[i]) {
			if (SCC[j] != SCC[i]) {
				indegree[SCC[j]]++;
			}
		}
	}
	int cnt = 0;
	int ans = 0;
	for (int i = 1; i <= scc_num; i++) {
		if (indegree[i] == 0) {
			ans = i;
			cnt++;
		}
	}
	if (cnt > 1) {
		cout << "Confused\n";
	}
	else {
		for (int i = 0; i < n; i++) {
			if (SCC[i] == ans) cout << i << "\n";
		}
	}
	cout << "\n";
	
}

int main() {
	int t;
	cin >> t;
	while (--t >= 0) {
		solve();
	}
}