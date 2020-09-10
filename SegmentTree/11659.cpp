#include <iostream>
#include <vector>
#include <cmath>
#define ll long long

using namespace std;

int main() {

	int n, m;
	vector <int> arr;
	scanf("%d %d", &n, &m);
	vector <ll> sum(n+1, 0);
	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);
		arr.push_back(num);
		sum[i + 1] = sum[i] + num;
	}

	for (int i = 0; i < m; i++) {
		int from, to;
		scanf("%d %d", &from, &to);
		printf("%d\n", sum[to] - sum[from - 1]);
	}
}