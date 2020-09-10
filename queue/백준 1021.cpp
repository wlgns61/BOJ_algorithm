#include <iostream>
#include <queue>
#include <vector>

using namespace std;

deque<int> dq;
vector<pair<int, int>> v;

void shift_letf() {
	dq.push_back(dq.front());
	dq.pop_front();
	for (int i = 0; i < v.size(); i++) {
		v[i].second--;
		if (v[i].second < 1) v[i].second = dq.size();
	}
}

void shift_right() {
	dq.push_front(dq.back());
	dq.pop_back();
	for (int i = 0; i < v.size(); i++) {
		v[i].second++;
		if (v[i].second > dq.size()) v[i].second = 1;
	}
}

int main() {
	int N, M;
	int cnt = 0;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		dq.push_back(i);
	}
	for (int i = 1; i <= M; i++) {
		int num;
		cin >> num;
		v.push_back({num, num}); // 숫자, 위치
	}
	int index = 0;
	while (index < M) { 
		if (v[index].first == dq.front()) {
			dq.pop_front();
			for (int i = 0; i < v.size(); i++) {
				v[i].second--;
			}
			index++;
		}
		else if (v[index].second > (dq.size() / 2) + 1) {
			shift_right();
			cnt++;
		}
		else if (v[index].second <= (dq.size() / 2) + 1) {
			shift_letf();
			cnt++;
		}
	}
	cout << cnt;
}
