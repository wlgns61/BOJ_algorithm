#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct info {
	int x;
	int y;
	int cost;
};
typedef info info;
vector <info> map;
int parent[10001];
int V, E;

bool compare(info x, info y) {
	if (x.cost < y.cost) {
		return true;
	}
	return false;
}

int find(int a) {
	if (parent[a] == a) {
		return a;
	}
	int root = find(parent[a]);
	return root;
}

bool Union(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) {
		parent[b] = a;
		return true;
	}
	return false;
}

int main() {
	cin >> V >> E;
	for (int i = 0; i <= V; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < E; i++) {
		int x, y, cost;
		cin >> x >> y >> cost;
		map.push_back({ x,y,cost });
	}
	sort(map.begin(), map.end(), compare);
	int result = 0;
	for (int i = 0; i < map.size(); i++) {
		bool decision = Union(map[i].x, map[i].y);
		if (decision) {
			result += map[i].cost;
		}
	}
	cout << result;
}