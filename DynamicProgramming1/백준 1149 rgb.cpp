#include <iostream>
#include <algorithm>

using namespace std;

int find_mincost(int N) {

	int RGB[3];
	int RGB_temp[3];
	int R, G, B;
	cin >> R >> G >> B;
	RGB[0] = R; RGB[1] = G; RGB[2] = B;
	for (int i = 1; i < N; i++) {
		cin >> R >> G >> B;
		for (int i = 0; i < 3; i++) {
			RGB_temp[i] = RGB[i];
		}
		RGB[0] = R + min(RGB_temp[1], RGB_temp[2]); //R�� ������ ���� ���� ���� ���
		RGB[1] = G + min(RGB_temp[0], RGB_temp[2]); //G�� ������ ���� ���� ���� ���
		RGB[2] = B + min(RGB_temp[0], RGB_temp[1]); //B�� ������ ���� ���� ���� ���
	}
	int min_ = RGB[0];
	for (int i = 1; i < 3; i++) {
		if (min_ > RGB[i]) min_ = RGB[i];
	}
	return min_;
}

int main() {
	int N;
	cin >> N;
	cout << find_mincost(N);

}