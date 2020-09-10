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
	while (left <= mid && right <= end) { // ���� ������ ������
		if (arr[left] <= arr[right]) {  //swap�� �Ͼ�� ����
			tmp.push_back(arr[left]);
			left++;
		}
		else { //swap�� �Ͼ�� ��� ������ ���� ���� ���� ��
			tmp.push_back(arr[right]);
			right++;
			result += (mid + 1 - left); // [0,0,0,*(2(left),0,0)*] [0,1(right),0,0,0,0] -> *���� ���� ��ŭ swap�� �Ͼ
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
	//���� ���� tmp�� �ϼ�, ���� ������ �����ش�.
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