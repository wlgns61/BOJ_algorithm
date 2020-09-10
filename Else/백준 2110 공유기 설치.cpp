#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<long long> homes;
long long n, c;
long long high;

long long counting(long long distance) {
	long long cnt = 1;
	int tmp = 0;
	for (int i = 0; i < n; i++) {
		if (distance <= homes[i] - homes[tmp]) {
			cnt++;
			tmp = i;
		}
	}
	return cnt;
}

long long search() {

	long long low = 1;
	long long result = 0; // ����

	while (low <= high) {

		long long mid = (low + high) / 2; // ��ġ�� ����
		long long cnt = counting(mid);

		if (cnt >= c) { // �� ���� ��ġ�ϰ� �ȴٸ� -> ������ ������ �� -> �� c�� ��ŭ ����� ��ġ ������ ���
			result = max(result, mid);
			low = mid + 1;
		}
		else {// �� ���� ��ġ�ϰ� �ȴٸ� -> ������ ������ ��
			high = mid - 1;
		}
	}
	return result;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		int coord;
		cin >> coord;
		homes.push_back(coord);
	}
	
	sort(homes.begin(), homes.end());
	high = homes.back();
	cout << search();

}