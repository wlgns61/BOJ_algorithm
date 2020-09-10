#include <iostream>
#include <queue>

using namespace std;

int main() {
	int T, M, N;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int cnt = 0;
		queue<pair<int, int>> q;
		priority_queue<int> pq;
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			int impt;
			cin >> impt;
			q.push(make_pair(i, impt));
			pq.push(impt);
		}
		while (!q.empty()) {
			int index = q.front().first;
			int value = q.front().second;
			q.pop();
			if (pq.top() == value) {
				pq.pop();
				cnt++;
				if (index == M) {
					cout << cnt <<"\n";
					break;
				}
			}
			q.push(make_pair(index, value));
		}
	}
}
