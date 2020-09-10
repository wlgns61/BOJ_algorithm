#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

priority_queue <int, vector<int>, greater<int>> pq;

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		scanf("%d", &num);
		if (num == 0) {
			if (pq.empty()) {
				printf("0\n");
			}
			else {
				printf("%d\n", pq.top());
				pq.pop();
			}
		}
		else {
			pq.push(num);
		}
	}
}