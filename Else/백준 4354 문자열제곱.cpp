#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> getpi(string str) {

	vector <int> pi(str.size(), 0);
	int j = 0;

	for (int i = 1; i < str.size(); i++) {
		while (0 < j && str[i] != str[j]) {
			j = pi[j - 1];
		}
		if (str[i] == str[j]) {
			pi[i] = ++j;
		}
	}
	return pi;
}

int countPattern(string str) {

	vector <int> pi = getpi(str);
	int patternSize = str.size() - pi.back(); //패턴의 길이가 결정
	if (str.size() / 2 > pi.back() || str.size()%patternSize != 0) { // aabaaba 이 경우에서 pattern= (aaba) 이지만, 문제의 결과에 성립하지 않음
		return 1;
	}
	else {
		return str.size() / patternSize;
	}
	
}

int main() {
	
	while (1) {
		string str;
		cin >> str;
		if (str.compare(".") == 0)
			break;
		cout << countPattern(str) <<"\n";
	}

}