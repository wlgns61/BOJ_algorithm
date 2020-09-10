#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <int> trees;
int n;
long long m;
long long high = 0;

long long cutResult(long long mid) {

	long long result = 0;
	for (int i = 0; i < trees.size(); i++) {
		long long left = trees[i] - mid;
		if (left >= 0)
			result += left;
	}
	return result;
}

int search() {
	
	long long low = 0;
	long long ret = 0;

	while (low <= high) {

		long long mid = (low + high) / 2;
		long long result = cutResult(mid);

		if (result < m) { //´ú Àß·ÇÀ»¶§ ³ôÀÌ¸¦ ³·Ãã
			high = mid - 1;
		}
		else { // ´õ Àß·ÈÀ» ¶§ ³ôÀÌ¸¦ ¿Ã¸²
			ret = max(ret, mid);
			low = mid + 1;
		}
	}
	return ret;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		long long num;
		cin >> num;
		high = max(high, num);
		trees.push_back(num);
	}
	cout << search();
}