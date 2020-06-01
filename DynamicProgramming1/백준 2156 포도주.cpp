#include <iostream>
#include <algorithm>
/*
- Dp[i-1] : ���� ������ �����ָ� ���� �ʾ��� ����

- wine[i] + Dp[i-2] : ������ �����ָ� ���ð� �������� �ȸ��� ���

- wine[i] + wine[i-1] + Dp[i-3] :������ �����ֿ� ������ �����ָ� ���� ���

*/

using namespace std;

int *wine;
int *total_wine;

int max_wine(int N) {
	if (N == 1) return wine[0];
	else if (N == 2) return wine[0] + wine[1];
	else if (N == 3) return max(wine[1] + wine[2], max(wine[0] + wine[1], wine[0] + wine[2]));
	else {
		total_wine[0] = wine[0];
		total_wine[1] = wine[0] + wine[1];
		total_wine[2] = max(wine[1] + wine[2], max(wine[0] + wine[1], wine[0] + wine[2]));
		for (int i = 3; i < N; i++) {
			total_wine[i] = max(total_wine[i - 2] + wine[i], total_wine[i - 3] + wine[i - 1] + wine[i]);
			total_wine[i] = max(total_wine[i], total_wine[i - 1]);
		}
		return total_wine[N - 1];
	}
	
}

int main() {
	int N;
	cin >> N;
	wine = new int[N];
	total_wine = new int[N];
	for (int i = 0; i < N; i++) {
		int capacity;
		cin >> capacity;
		wine[i] = capacity;
		total_wine[i] = 0;
	}
	cout << max_wine(N);

}
