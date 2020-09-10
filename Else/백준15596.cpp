#include <iostream>
#include <vector>

using namespace std;

long sum(std::vector<int> &a) {
	int i;
	int a_sum = 0;
	for (i = 0; i < a.size(); i++) {
		a_sum = a_sum + a[i];
	}
	return a_sum;
}

int main() {
	
	int n = 0, i = 0;
	int x = 0;
	int a_sum;
	cin >> n;
	vector<int> a;
	a.assign(n, 0);
	for (i = 0; i < n; i++) {
		cin >> x;
		a[i] = x;
	}
	a_sum = sum(a);
	cout << a_sum;
}