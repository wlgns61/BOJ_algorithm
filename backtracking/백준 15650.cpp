#include <iostream>

using namespace std;

const int MAX = 8 + 1;
int arr[MAX] = { 0 };
bool visited[MAX];
int M, N;

void func(int cnt, int index) {

	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = index; i <= N; i++) {
		if (visited[i] == false) {
			visited[i] = true;
			arr[cnt] = i;
			func(cnt + 1, i + 1);
			visited[i] = false;
		}
	}
}

int main() {
	cin >> N >> M;
	func(0, 1);
}