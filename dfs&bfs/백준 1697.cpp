#include <iostream>
#include <queue>

using namespace std;

queue <int> q;
int visited[100001] = {0,};

int N, K;
int result = 0;

int bfs(int now) {

	while (true) {
		if (!q.empty()) {
			now = q.front();
			q.pop();
		}

		int next1 = now + 1;
		int next2 = now - 1;
		int next3 = now * 2;
		
		if (0 <= next1 && next1 <= 100000 && visited[next1]==0) {
			q.push(next1);
			visited[next1] = visited[now] + 1;
		}
		if (0 <= next2 && next2 <= 100000 && visited[next2] == 0) {
			q.push(next2);
			visited[next2] = visited[now] + 1;
		}
		if (0 <= next3 && next3 <= 100000 && visited[next3] == 0) {
			q.push(next3);
			visited[next3] = visited[now] + 1;
		}
		if (next1 == K || next2 == K || next3 == K) {
			return visited[K];
		}
	}
}

int main() {
	
	cin >> N >> K;
	q.push(N);
	if (N == K) {
		cout << 0;
	}
	else {
		cout << bfs(N);
	}
}
