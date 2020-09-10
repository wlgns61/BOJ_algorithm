//Ÿ�� �˰��� �̹� �湮�� ���� �� ������ �Ҷ�(����Ŭ�� �̷���� �� ��)
//���� ó������ �湮�Ѱ�(discover�� ����������)�� ���� ���������� �湮�� ���� ����ũ�� ����Ŭ�� �̷���̴�.
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
		if (discover[next] == 0) { // �湮������ ���ٸ�
			ret = min(ret, dfs(next));
		}
		else if (scc_color[next] == 0) { //�湮�� ������, scc�� �̷��� �ʾҴٸ�
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
				if( next_scc != i) { //���� scc�� �ƴ�, �ٸ� scc�� ���� ��
					dp[next_scc] = max(dp[next_scc], dp[i] + scc_cost[next_scc]);
				}
			}
		}
	}
	int result = 0;
	for (int i = 1; i <= n; i++) {
		if (finish[i] && discover[i] != 0) { //�߰ߵ� �� �ִ� ����, �� �� �ִ� ����
			int scc_num = scc_color[i];
			result = max(result, dp[scc_num]);
		}
	}
	cout << result;
}