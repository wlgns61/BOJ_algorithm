#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
typedef long long ll;
vector <pair<ll, ll>> v;

ll CCW(pair<ll, ll> one, pair<ll, ll> two, pair<ll, ll> thr) {
	ll first = (thr.first - one.first) * (two.second - one.second);
	ll second = (thr.second - one.second) * (two.first - one.first);
	return first - second;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}
	ll sum = 0;
	for (int i = 1; i < v.size() - 1; i++) {
		sum += CCW(v[0], v[i], v[i + 1]);
	}
	cout << fixed;
	cout.precision(1);
	sum = abs(sum);
	cout << double(sum) / 2.0;
}
