#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string.h>
#include <cmath>
#define SIZE 2020

using namespace std;

vector <vector<int>> scc;
vector <vector<int>> graph(SIZE);
stack <int> st;
int discover[SIZE];
int scc_color[SIZE];
int cnt, color;
int n, m;

int tarjan(int now) {

	discover[now] = cnt++;
	int ret = discover[now];
	st.push(now);

	for (auto next : graph[now]) {
		if (discover[next] == 0) //아직 방문 하지 않았다면
			ret = min(ret, tarjan(next));
		else if (scc_color[next] == 0) //아직 scc를 이루지 않았다면
			ret = min(ret, discover[next]);
	}

	if (ret == discover[now]) {
		vector <int> tmp;
		while (true) {
			int top = st.top();
			st.pop();
			scc_color[top] = color;
			tmp.push_back(top);
			if (top == now)
				break;
		}
		sort(tmp.begin(), tmp.end());
		scc.push_back(tmp);
		color++;
	}
	return ret;
}

void init() {
	
	scc = vector <vector<int>>();
	graph = vector <vector<int>>(SIZE);
	st = stack <int>();
	memset(discover, 0, sizeof(discover));
	memset(scc_color, 0, sizeof(scc_color));
	cnt = 1;
	color = 1;
}

void solve() {

	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		graph[-a + 1000].push_back(b + 1000);
		graph[-b + 1000].push_back(a + 1000);
	}
	graph[-1 + 1000].push_back(1 + 1000);

	for (int i = -n + 1000; i <= n + 1000; i++) {
		if (i == 1000)
			continue;
		if (discover[i] == 0)
			tarjan(i);
	}
	int flag = 1;
	
	for (auto elem : scc) {
		for (int i = 0; i < elem.size() - 1; i++) {
			for (int j = i + 1; j < elem.size(); j++) {
				if (elem[i] + elem[j] == 2000) {
					flag = 0;
					break;
				}
			}
		}
	}
	
	if (flag)
		cout << "yes\n";
	else
		cout << "no\n";
}

int main() {
	
	while (scanf("%d %d", &n, &m) == 2) {
		init();
		solve();
	}
}
