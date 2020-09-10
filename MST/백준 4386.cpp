#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;
struct info {
	int x;
	int y;
	float cost;
};
typedef info info;
vector <info> map;
vector <pair <float, float>> star;
int parent[101];
int V;

float distance(pair<float, float> a, pair<float, float> b) {
	float x2 = float(pow(abs(a.first - b.first), 2));
	float y2 = float(pow(abs(a.second- b.second), 2));
	return float(pow(x2 + y2, 0.5));
}

bool compare(info a, info b) {
		return a.cost < b.cost;
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
	cin >> V;
	for (int i = 0; i <= V; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < V; i++) {
		float x, y;
		cin >> x >> y;
		star.push_back({ x,y });
	}
	for (int i = 0; i < star.size(); i++) {
		for (int j = i; j < star.size(); j++) {
			float dist = distance(star[i], star[j]);
			map.push_back({ i, j, dist });
		}
	}
	sort(map.begin(), map.end(), compare);
	float result = 0;
	for (int i = 0; i < map.size(); i++) {
		bool discr = Union(map[i].x, map[i].y);
		if (discr)
			result += map[i].cost;
	}
	cout << fixed;
	cout.precision(2);
	cout << result;
}