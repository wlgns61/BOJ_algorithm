#include <iostream>
#include <stack>
#include <queue>
#include <string.h>

using namespace std;

pair<int, int> visited[100001];
queue <int> q; //now, past
int N, K;

void solve(int n) {

	int now = n, past = n;
	q.push(now);
	while (true) {
		if (!q.empty()) {
			now = q.front();
			q.pop();
		}
		int next1 = now + 1;
		int next2 = now - 1;
		int next3 = now * 2;
		if (0 <= next1 && next1 <= 100000 && visited[next1].first == 0) {
			q.push(next1);
			visited[next1].first = visited[now].first + 1;
			visited[next1].second = now;
		}
		if (0 <= next2 && next2 <= 100000 && visited[next2].first == 0) {
			q.push(next2);
			visited[next2].first = visited[now].first + 1;
			visited[next2].second = now;
		}
		if (0 <= next3 && next3 <= 100000 && visited[next3].first == 0) {
			q.push(next3);
			visited[next3].first = visited[now].first + 1;
			visited[next3].second = now;
		}
		if (next1 == K || next2 == K || next3 == K) {
			return;
		}
	}
}

void print() {
	stack <int> st;
	int past = K;
	st.push(past);
	while (true) {
		past = visited[past].second;
		st.push(past);
		if (past == N) break;
	}
	cout << st.size() - 1 << "\n";
	while (!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}
}

int main() {
	
	cin >> N >> K;
	if (N == K) {
		cout << "0\n" <<  N;
	}
	else {
		solve(N);
		print();
	}
}