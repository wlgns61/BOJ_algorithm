#include <iostream>

using namespace std;

bool *q;

int main() {
	int N;
	int K;
	cin >> N >> K;
	q = new bool[N + 1];
	for (int i = 0; i <= N; i++) {
		q[i] = false;
	}
	int index = 1;
	cout << "<";
	for (int i = 1; i <= N; i++) {
		int cnt = 0;
		while (cnt < K) {
			if (q[index] == false) {
				cnt++;
				if (cnt == K) break;
			}
			index++;
			if (index > N) {
				index = 1;
			}
		}
		q[index] = true;
		if (i < N) cout << index << ", ";
		else cout << index;
	}
	cout << ">";
}