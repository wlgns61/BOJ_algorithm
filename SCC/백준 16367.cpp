#include <iostream>
#include <stack>
#include <vector>
#include <string.h>
#include <algorithm>
#include <cmath>

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

int main() {

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		char l1, l2, l3;
		cin >> a >> l1 >> b >> l2 >> c >> l3;
		if (l1 == 'R') a = -a; //R을 not으로 판단
		if (l2 == 'R') b = -b;
		if (l3 == 'R') c = -c;
		graph[-a + 10000].push_back(b + 10000);
		graph[-b + 10000].push_back(a + 10000);
		graph[-b + 10000].push_back(c + 10000);
		graph[-c + 10000].push_back(b + 10000);
		graph[-c + 10000].push_back(a + 10000);
		graph[-a + 10000].push_back(c + 10000);
	}

	for (int i = -n + 10000; i <= n + 10000; i++) {
		if (i == 10000)
			continue;
		if (discover[i] == 0)
			tarjan(i);
	}

	int flag = 1;
	color--;

	for (int idx = color; idx > 0; idx--) {
		auto elem = scc[idx - 1];
		for (int i = 0; i < elem.size(); i++) {
			for (int j = i + 1; j < elem.size(); j++) {
				if (elem[i] + elem[j] == 20000) {
					flag = 0;
					break;
				}
			}
		}
	}
	if (flag == 1) {
		for (int i = 1; i <= n; i++)
			printf("%c", scc_color[i + 10000] < scc_color[10000 - i] ? 'R':'B'); //이 부분이 이해가 안가요 ㅜㅜㅜㅜㅜㅜ
	}
	else
		cout << -1;
}