#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long result = 0;

void merge(vector <int> &arr, int start, int end) {
	
	int mid = (start + end) / 2;
	int left = start;
	int right = mid + 1;

	if (start == end)
		return;

	merge(arr, start, mid);
	merge(arr, mid + 1, end);

	vector <int> tmp;
	while (left <= mid && right <= end) { // 정상 범위에 있을때
		if (arr[left] <= arr[right]) {  //swap이 일어나지 않음
			tmp.push_back(arr[left]);
			left++;
		}
		else { //swap이 일어나는 경우 우측이 좌측 보다 작을 때
			tmp.push_back(arr[right]);
			right++;
			result += (mid + 1 - left); // [0,0,0,*(2(left),0,0)*] [0,1(right),0,0,0,0] -> *사이 간격 만큼 swap이 일어남
		}
	}

	while (left <= mid) {
		tmp.push_back(arr[left]);
		left++;
	}
	while (right <= end) {
		tmp.push_back(arr[right]);
		right++;
	}
	//여기 까지 tmp의 완성, 이후 병합을 시켜준다.
	for (int i = start, j = 0; i <= end; i++, j++) {
		arr[i] = tmp[j];
	}
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector <int> arr;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		arr.push_back(num);
	}
	merge(arr, 0, n - 1);
	cout << result;
}