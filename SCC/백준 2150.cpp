#include <iostream>
#include <vector>
#include <string.h>
#include <stack>
#include <algorithm>

using namespace std;

vector <int> adj[10001], rev_adj[10001];
vector <vector <int>> SCC(10001);
bool visited[10001];
stack <int> st;

void dfs(int now) {
	visited[now] = true;
	for (int i = 0; i < adj[now].size(); i++) {
		int next = adj[now][i];
		if (visited[next] == false)
			dfs(next);
	}
	st.push(now); //가장 끝이 최초로 들어감, 그래야 스택의 가장위에 시작점이 존재하게 됨
}

void strong_connect(int now, int idx) {
	visited[now] = true;
	SCC[idx].push_back(now);
	for (int i = 0; i < rev_adj[now].size(); i++) {
		int next = rev_adj[now][i];
		if (visited[next] == false)
			strong_connect(next, idx);
	}
}

int main() {
	int v, e;
	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		int from, to;
		cin >> from >> to;
		adj[from].push_back(to);
		rev_adj[to].push_back(from);
	}
	for (int i = 1; i <= v; i++) {
		if (visited[i] == false)
			dfs(i);
	}
	memset(visited, 0, sizeof(visited));
	int idx = -1;
	while (!st.empty()) {
		int top = st.top();
		st.pop();
		if (visited[top] == true) 
			continue;
		strong_connect(top, ++idx);
	}
	cout << idx + 1 << "\n";
	SCC.resize(idx + 1);
	for (int i = 0; i <= idx; i++) 
		sort(SCC[i].begin(), SCC[i].end());
	sort(SCC.begin(), SCC.end());

	for (int i = 0; i <= idx; i++){
		for (int j = 0; j < SCC[i].size(); j++) 
			cout << SCC[i][j] << ' ';
		cout << -1 << '\n';
	}
}