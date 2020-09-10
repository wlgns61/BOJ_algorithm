#include <iostream>
#include <algorithm>

using namespace std;

int *arr;
int N, C;

void solve() {
	int end = arr[N - 1];
	int start = 1;
	int distance;
	int result = 0;
	while (end >= start) {
		int cnt = 1;
		distance = (start + end) / 2;
		int tmp = 0;
		for (int i = 0; i < N; i++) {
			if (arr[i] - arr[tmp] >= distance) {
				cnt++;
				tmp = i;
			}
		}
		if (cnt >= C) { //�� ���� ��ġ ���� ��, ������ ������ �� 
						//�� �´� ������ ��ġ�� �Ǿ�� ������ ������ �� �� ����
			result = max(result, distance);
			start = distance + 1;
		}
		else { //�� ���� ��ġ������, ������ �ٿ�����
			end = distance - 1;
		}
	}
	cout << result;

}

int main() {
	
	cin >> N >> C;
	arr = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	solve();

}