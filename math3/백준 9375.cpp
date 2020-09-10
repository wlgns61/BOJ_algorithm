#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	vector<pair<string, int>> fashion;
	int N;
	cin >> N;
	string kind;
	string name;
	for (int i = 0; i < N; i++) {
		int cnt;
		int result = 1;
		cin >> cnt;
		for (int i = 0; i < cnt; i++) {
			cin >> name >> kind;
			if (fashion.size() < 1) {
				fashion.push_back(make_pair(kind, 1));
			}
			else {
				int j = 0;
				for (j = 0; j < fashion.size(); j++) {
					if (kind.compare(fashion[j].first) == 0) {
						fashion[j].second++;
						break;
					}
				}
				if (j == fashion.size()) {
					fashion.push_back(make_pair(kind, 1));
				}
			}
		}
		for (int i = 0; i < fashion.size(); i++) {
			result *= (fashion[i].second + 1);
		}
		cout << result - 1 << "\n";
		fashion.clear();
	}

}