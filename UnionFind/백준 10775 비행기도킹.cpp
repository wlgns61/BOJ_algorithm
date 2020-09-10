#include <iostream>
#include <algorithm>

using namespace std;

int gate[100001];
int cnt[100001];

int find(int x) {
	if (gate[x] == x) {
		return x;
	}
	int root = find(gate[x]);
	return gate[x] = root;
}

void Union(int x, int y) {
	x = find(x);
	y = find(y);
	gate[y] = x;
}

int main() {
	int G, P;
	bool flag = false;
	int result = 0;
	scanf("%d %d", &G, &P);
	fill_n(cnt, G+1, 1);
	for (int i = 0; i <= G; i++) {
		gate[i] = i;
	}
	for (int i = 0; i < P; i++) {
		int gi;
		scanf("%d", &gi);
		if (flag == true)
			continue;
		gi = find(gi);
		if (gi == 0) {
			flag = true;
		}
		else {
			result++;
			Union(gi - 1, gi);
		}
	}
	printf("%d", result);
}