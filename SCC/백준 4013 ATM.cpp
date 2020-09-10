//타잔 알고리즘 이미 방문한 곳을 또 가려고 할때(사이클을 이루려고 할 때)
//가장 처음으로 방문한곳(discover가 가장작은곳)이 가장 마지막으로 방문한 곳과 가장크게 사이클을 이룰것이다.
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

vector <vector<int>> ans;
vector <int> graph[500003];
stack <int> st;
bool finish[500003];
int cost[500003];
int scc_cost[500003];
int discover[500003];
int scc_color[500003];
int dp[500003];
int color = 1;
int cnt = 1;

int dfs(int now) {
	
	discover[now] = cnt++;
	int ret = discover[now];
	st.push(now);
	for (auto next : graph[now]) {
		if (discover[next] == 0) { // 방문한적이 없다면
			ret = min(ret, dfs(next));
		}
		else if (scc_color[next] == 0) { //방문은 했으나, scc를 이루지 않았다면
			ret = min(ret, discover[next]); 
		}
	}
	if (ret == discover[now]) {
		vector <int> tmp;
		while (true) {
			int top = st.top(); 
			st.pop();
			scc_color[top] = color;
			scc_cost[color] += cost[top];
			tmp.push_back(top);
			if (top == now)
				break;
		}
		sort(tmp.begin(), tmp.end());
		ans.push_back(tmp);
		color++;
	}
	return ret;
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
	}
	for (int i = 1; i <= n; i++) {
		cin >> cost[i];
	}

	int start, end_num;
	cin >> start >> end_num;
	for (int i = 0; i < end_num; i++) {
		int end;
		cin >> end;
		finish[end] = true;
	}
	dfs(start);
	color--;
	dp[color] = scc_cost[color];
	for (int i = color; i > 0; i--) {
		for (auto elem : ans[i - 1]) { 
			for (auto next : graph[elem]) {
				int next_scc = scc_color[next];
				if( next_scc != i) { //같은 scc가 아닌, 다른 scc로 향할 때
					dp[next_scc] = max(dp[next_scc], dp[i] + scc_cost[next_scc]);
				}
			}
		}
	}
	int result = 0;
	for (int i = 1; i <= n; i++) {
		if (finish[i] && discover[i] != 0) { //발견된 적 있는 지점, 갈 수 있는 지점
			int scc_num = scc_color[i];
			result = max(result, dp[scc_num]);
		}
	}
	cout << result;
}