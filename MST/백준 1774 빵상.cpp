#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

struct info {
	int x;
	int y;
	double cost;
};
typedef info info;
vector <info> map;
int parent[1001];
vector <pair <int, int>> god;
int V, connect;

double distance(pair<int, int> a, pair<int, int> b) {
	long long x = (a.first - b.first);
	long long y = (a.second - b.second);
	long long x2 = x * x;
	long long y2 = y * y;
	return double(sqrt(x2 + y2));
}

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
	cin >> V >> connect;
	for (int i = 0; i <= V; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < V; i++) {
		int x, y;
		cin >> x >> y;
		god.push_back({ x,y });
	}
	for (int i = 0; i < god.size(); i++) {
		for (int j = i + 1; j < god.size(); j++) {
			double dist = distance(god[i], god[j]);
			map.push_back({ i, j, dist });
		}
	}
	double result = 0;
	for (int i = 0; i < connect; i++) {
		int x, y;
		cin >> x >> y;
		Union(x - 1, y - 1);
	}
	sort(map.begin(), map.end(), compare);
	for (int i = 0; i < map.size(); i++) {
		bool discr = Union(map[i].x, map[i].y);
		if (discr)
			result += map[i].cost;
	}
	cout << fixed;
	cout.precision(2);
	cout << result;
}