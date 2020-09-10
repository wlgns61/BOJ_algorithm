#include <stdio.h>
#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

priority_queue <int, vector<int>, greater<int>> positive;
priority_queue <int, vector<int>, greater<int>> negative;

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		scanf("%d", &num);
		if (num == 0) {
			if (positive.empty() && negative.empty()) {
				printf("0\n");
			}
			else if(positive.empty() == 0 && negative.empty() == 1){
				printf("%d\n", positive.top());
				positive.pop();
			}
			else if (positive.empty() == 1 && negative.empty() == 0) {
				printf("%d\n", -1 * negative.top());
				negative.pop();
			}
			else {
				if (positive.top() == negative.top()) {
					printf("%d\n", -1 * negative.top());
					negative.pop();
				}
				else {
					if(negative.top() > positive.top()){
						printf("%d\n", positive.top());
						positive.pop();
					}
					else {
						printf("%d\n", -1 * negative.top());
						negative.pop();
					}
				}
			}
		}
		else {
			if (num > 0) {
				positive.push(num);
			}
			else if(num < 0){
				negative.push(abs(num));
			}
		}
	}
	
}