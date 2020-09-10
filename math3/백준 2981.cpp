#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> result;
int *arr;

int GCD(int a, int b){
	if (a % b == 0){
		return b;
	}
	return GCD(b, a % b);
}

int main() {

	int N;
	cin >> N;
	arr = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	int gcd = arr[1] - arr[0];
	for (int i = 2; i < N; i++) {
		gcd = GCD(gcd, arr[i] - arr[i - 1]);
	}
	for (int i = 1; i*i <= gcd; i++) {
		if (gcd%i == 0) {
			result.push_back(i);
			result.push_back(gcd/i);
		}
	}
	sort(result.begin(), result.end());
	result.erase(unique(result.begin(), result.end()), result.end());
	for (int i = 1; i < result.size(); i++) {
		cout << result[i] << " ";
	}
}