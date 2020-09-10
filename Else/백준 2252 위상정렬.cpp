#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int> v[32001];
int indegree[32001];
int n, m;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
		
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		indegree[b]++;
	}

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0)
			q.push(i);
	}

	while (!q.empty()) {

		int now = q.front();
		q.pop();

		cout << now << " ";

		for (int i = 0; i < v[now].size(); i++) {
			if (--indegree[v[now][i]] == 0) {
				q.push(v[now][i]);
			}
		}
	}
}
