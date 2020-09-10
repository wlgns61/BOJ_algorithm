#include <iostream>
#include <algorithm>

// tip::: 1~100까지 5의배수의 갯수: 100/5 + 100/25 + 100/125 ... 24개

using namespace std;

int count_two(int num) {
	int cnt = 0;
	long long i = 2;
	while (num >= i) {
		cnt += num / i;
		i *= 2;
	}
	return cnt;
}

int count_five(int num) {
	int cnt = 0;
	long long i = 5;
	while (num >= i) {
		cnt += num / i;
		i *= 5;
	}
	return cnt;
}

int main() {
	int n, m;
	int two = 0, five = 0;
	cin >> n >> m;

	two += count_two(n);
	five += count_five(n);
	if (m != 0) two -= count_two(m);
	if (m != 0) five -= count_five(m);
	if (n != m) two -= count_two(n - m);
	if (n != m) five -= count_five(n - m);
	
	cout << min(two, five);
}