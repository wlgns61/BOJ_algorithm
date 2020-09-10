#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

priority_queue <int, vector<int>, greater<int>> min_heap;
priority_queue <int, vector<int>, less<int>> max_heap;

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		scanf("%d", &num);
		if (min_heap.size() == max_heap.size()) {
			min_heap.push(num);
		}
		else {
			max_heap.push(num);
		}
		if (i == 0) {
			cout << num << "\n";
			continue;
		}
		if (min_heap.top() < max_heap.top()) {
			int min_tmp = min_heap.top();
			int max_tmp = max_heap.top();
			min_heap.pop();
			min_heap.push(max_tmp);
			max_heap.pop();
			max_heap.push(min_tmp);
		}
		if (i % 2 == 0) {
			cout << min_heap.top() << "\n";
		}
		else {
			cout << max_heap.top() << "\n";
		}
		
	}
}