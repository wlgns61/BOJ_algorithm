#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct loc {
	int x;
	int y;
};
vector <pair<loc, loc>> v;
int parent[3001];
int cnt[3001];
int result = 1;

int find(int a) {
	if (parent[a] == a) {
		return a;
	}
	int root = find(parent[a]);
	return parent[a] = root;
}

void Union(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) {
		parent[b] = a; // a를 루트로 가짐
		cnt[a] += cnt[b];
		cnt[b] = 0;
		result = max(result, cnt[a]);
	}
}

int CCW(loc a, loc b, loc c) {
	int first = a.x * b.y + b.x * c.y + c.x * a.y;
	int second = b.x * a.y + c.x * b.y + a.x * c.y;
	int result = first - second;
	if (result < 0) return -1;
	else if (result == 0) return 0;
	else return 1;
}

bool iscrossed(pair<loc, loc> line1, pair<loc, loc> line2) {
	int t1 = CCW(line1.first, line1.second, line2.first) * CCW(line1.first, line1.second, line2.second);
	int t2 = CCW(line2.first, line2.second, line1.first) * CCW(line2.first, line2.second, line1.second);
	if (t1 <= 0 && t2 <= 0) { //교차할 가능성이 있는경우
		if (max(line2.first.x, line2.second.x) < min(line1.first.x, line1.second.x)
			|| min(line2.first.x, line2.second.x) > max(line1.first.x, line1.second.x)) return false; //교차x
		else if (max(line2.first.y, line2.second.y) < min(line1.first.y, line1.second.y)
			|| min(line2.first.y, line2.second.y) > max(line1.first.y, line1.second.y)) return false; //교차x
		return true;
	}
	return false;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		v.push_back({ {x1,y1}, {x2,y2} });
	}
	for (int i = 0; i < 3001; i++) {
		cnt[i] = 1;
		parent[i] = i;
	}
	for (int i = 0; i < v.size(); i++) {
		for (int j = i+1; j < v.size(); j++) {
			if (iscrossed(v[i], v[j])) {
				Union(i, j);
			}
		}
	}
	int result1 = 0;
	for (int i = 0; i < v.size(); i++) {
		if (cnt[i] > 0) result1++;
	}
	cout << result1 << "\n" << result;
}