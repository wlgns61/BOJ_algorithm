#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> graph[20002];
vector <vector<int>> scc;
stack <int> st;
int discover[20002];
int scc_color[20002];
int cnt = 1;
int color = 1;

int tarjan(int now) {

	discover[now] = cnt++;
	int ret = discover[now];
	st.push(now);

	for (auto next : graph[now]) {
		if (discover[next] == 0) {
			ret = min(ret, tarjan(next));
		}
		else if (scc_color[next] == 0) {
			ret = min(ret, discover[next]);
		}
	}

	if (ret == discover[now]) {
		vector <int> tmp;
		while (true) {
			int top = st.top();
			st.pop();
			tmp.push_back(top);
			scc_color[top] = color;
			if (top == now)
				break;
		}
		sort(tmp.begin(), tmp.end());
		scc.push_back(tmp);
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
		graph[-a+10000].push_back(b+10000);
		graph[-b+10000].push_back(a+10000);
	}

	for (int i = -n + 10000; i <= n+10000; i++) {
		if (i == 10000)
			continue;
		if (discover[i] == 0) 
			tarjan(i);
	}

	int flag = 1;
	for (auto elem : scc) {
		for (int i = 0; i < elem.size(); i++) {
			for (int j = i + 1; j < elem.size(); j++) {
				if (elem[i] + elem[j] == 20000) {
					flag = 0;
					break;
				}
			}
		}
	}
	cout << flag;
}