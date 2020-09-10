#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int indegree[32001];
vector <int> v[32001];
int n, m;

int main() {
	
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		indegree[b]++;
	}

	priority_queue <int, vector<int>, greater<int>> pq;
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0)
			pq.push(i);
	}

	while (!pq.empty()) {
		
		int now = pq.top();
		pq.pop();
		cout << now << " ";
		
		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i];
			if (--indegree[next] == 0) {
				pq.push(next);
			}
		}
	}
}