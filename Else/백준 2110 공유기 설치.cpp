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
	long long result = 0; // 간격

	while (low <= high) {

		long long mid = (low + high) / 2; // 설치할 간격
		long long cnt = counting(mid);

		if (cnt >= c) { // 더 많이 설치하게 된다면 -> 간격을 넓혀야 함 -> 즉 c개 만큼 충분히 설치 가능한 경우
			result = max(result, mid);
			low = mid + 1;
		}
		else {// 더 조금 설치하게 된다면 -> 간격을 좁혀야 함
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