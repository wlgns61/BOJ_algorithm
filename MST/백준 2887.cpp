#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

struct location {
	int idx;
	int x;
	int y;
	int z;
};
typedef location location;

struct info {
	int i, j, cost;
};
typedef info info;

vector <location> v;
vector <info> map; 
int parent[100001];

int distance(location a, location b) {
	return min(abs(a.x - b.x), min(abs(a.y - b.y), abs(a.z - b.z)));
}

bool compx(location a, location b) {
	return a.x < b.x;
}

bool compy(location a, location b) {
	return a.y < b.y;
}

bool compz(location a, location b) {
	return a.z < b.z;
}

bool compd(info a, info b) {
	return a.cost < b.cost;
}

int find(int a) {
	if (parent[a] == a)
		return a;
	int root = find(parent[a]);
	return parent[a] = root;
}

bool Union(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)
		return false; // 같은 루트이면
	parent[b] = a;
	return true;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		v.push_back({ i,x,y,z });
		parent[i] = i;
	}
	sort(v.begin(), v.end(), compx);
	for (int i = 0; i < n - 1; i++) 
		map.push_back({ v[i].idx, v[i + 1].idx, abs(v[i].x - v[i + 1].x) });
	sort(v.begin(), v.end(), compy);
	for (int i = 0; i < n - 1; i++)
		map.push_back({ v[i].idx, v[i + 1].idx, abs(v[i].y - v[i + 1].y) });
	sort(v.begin(), v.end(), compz);
	for (int i = 0; i < n - 1; i++)
		map.push_back({ v[i].idx, v[i + 1].idx, abs(v[i].z - v[i + 1].z) });
	sort(map.begin(), map.end(), compd);

	int result = 0;
	for (int i = 0; i < map.size(); i++) {
		bool flag = Union(map[i].i, map[i].j);
		if (flag)
			result += map[i].cost;
	}
	cout << result;
}