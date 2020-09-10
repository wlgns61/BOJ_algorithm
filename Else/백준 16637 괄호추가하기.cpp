#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector <long long> numbers;
vector <char> tokens;
bool visited[20];
long long ans = -9999999999;

long long part_calc(long long a, long long b, char token) {

	long long result = 0;
	if (token == '*')
		result = a * b;
	else if (token == '+') 
		result = a + b;
	else if (token == '-') 
		result = a - b;

	return result;
}

long long calc_result() {

	vector <long long> tmpnumbers;
	vector <char> tmptokens;
	vector <bool> visited_t(tokens.size());
	long long result;
	
	for (int i = 0; i < numbers.size(); i++) {
		if (i < numbers.size() -1 && visited[i] && visited[i + 1]) {
			tmpnumbers.push_back(part_calc(numbers[i], numbers[i + 1], tokens[i]));
			visited_t[i] = true;
			i += 1;
		}
		else 
			tmpnumbers.push_back(numbers[i]);
	}
	for (int i = 0; i < tokens.size(); i++) 
		if (!visited_t[i]) 
			tmptokens.push_back(tokens[i]);

	result = tmpnumbers[0];
	for (int i = 1; i < tmpnumbers.size(); i++) 
		result = part_calc(result, tmpnumbers[i], tmptokens[i - 1]);

	return result;
}

void solve(int now) {

	for (int i = now; i < numbers.size() - 1; i++) {
		if (visited[i] == false) {
			visited[i] = visited[i + 1] = true;
			ans = max(ans, calc_result());
			solve(i + 1);
			visited[i] = visited[i + 1] = false;	
		}
	}
	
}

int main() {

	cin >> n;
	for (int i = 0; i <= n/2; i++) {
		int num;
		char token;
		scanf("%1d", &num);
		numbers.push_back(num);
		if (n / 2 != i) {
			scanf("%c", &token);
			tokens.push_back(token);
		}
	}
	solve(0);
	if (n == 1)
		cout << numbers[0];
	else
		cout << ans;
}