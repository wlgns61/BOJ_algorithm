#include <iostream>

int main() {
	int T, N, M;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d %d", &N, &M);
		for (int j = 0; j < M; j++) {
			int a, b;
			scanf("%d %d", &a, &b);
		}
		printf("%d\n", N - 1);
	}
}