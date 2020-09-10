#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

void DSLR(int start, int end) {
	pair <int, char> visited[10000]; //past_num, operator
	for (int i = 0; i < 10000; i++) {
		visited[i].first = -1;
	}
	queue <int> q; 
	visited[start].first = start;
	visited[start].second = 'X';
	q.push(start);
	while (!q.empty()) {
		
		int now = q.front();
		q.pop();
		int D = (now * 2) % 10000;
		int S = (now - 1 >= 0) ? now - 1 : 9999;
		int L = (now - 1000 * (now / 1000)) * 10 + (now / 1000);
		int R = (now - now % 10) / 10 + 1000 * (now % 10);
		if (visited[D].first == -1) {
			visited[D].first = now;
			visited[D].second = 'D';
			q.push(D);
		}
		if (visited[S].first == -1) {
			visited[S].first = now;
			visited[S].second = 'S';
			q.push(S);
		}
		if (visited[L].first == -1) {
			visited[L].first = now;
			visited[L].second = 'L';
			q.push(L);
		}
		if (visited[R].first == -1) {
			visited[R].first = now;
			visited[R].second = 'R';
			q.push(R);
		}
		if (D == end || S == end || L == end || R == end) {
			break;
		}
	}

	stack <char> st;
	int past = end;
	st.push(visited[past].second);
	while (true) {
		past = visited[past].first;
		if (visited[past].second == 'X') break;
		st.push(visited[past].second);
	}
	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}
	cout << "\n";
	
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int start, end;
		cin >> start >> end;
		DSLR(start, end);
	}
}