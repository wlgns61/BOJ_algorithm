#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>

using namespace std;

int parent[50001];
int visited[50001];
vector <int> v[50001];

int find(int a) {
	if (parent[a] == a) {
		return a;
	}
	return parent[a] = find(parent[a]);
}

void Union(int a, int b) {
	a = find(a);
	b = find(b);
	parent[b] = a;
}

bool find_cycle(int here) {

	if (visited[here]) {
		if (visited[here] == -1) {
			return true;
		}
		return false;
	}

	visited[here] = -1; //현재 방문지점
	for (int i = 0; i < v[here].size(); i++) {
		if (find_cycle(v[here][i]))
			return true;
	}
	visited[here] = 1; //사이클 없이 끝까지 왔을 때
	return false;
}

int main() {
	for (int i = 0; i <= 50000; i++) {
		parent[i] = i;
	}
	int N, M;
	vector <pair<int, int>> temp;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		int a, b;
		char token;
		scanf("%d %c %d", &a, &token, &b);
		if (token == '=') Union(a, b);
		else if (token == '>') {
			temp.push_back({ a,b });
		}
	}
	for (auto &values : temp) {
		v[find(values.first)].push_back(find(values.second));
	}
	for (int i = 0; i < N; ++i) {
		if (find_cycle(i)) {
			puts("inconsistent");
			return 0;
		}
	}
	puts("consistent");
}