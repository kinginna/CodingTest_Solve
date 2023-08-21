#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <deque>
using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int roop = 3;

	while (roop--) {
		int itemCount;
		cin >> itemCount;
		vector<vector<bool>> table(itemCount + 1, vector<bool>(50001, false));
		vector<pair<int, int>> item(itemCount + 1);
		int totalV = 0;
		for (int i = 1; i <= itemCount; i++) {
			int V, C;
			cin >> V >> C;
			totalV += V * C;
			item[i] = { V,C };
			for (int j = 1; j <= C; j++) {
				if (j * V > 50000) break;
				table[i][j * V] = true;
			}
		}

		if (totalV % 2 == 1) {
			cout << 0 << endl;
			continue;
		}
		totalV /= 2;
		for (int i = 1; i <= itemCount; i++) {
			for (int j = 0; j <= totalV; j++) {
				if (table[i][j]) continue;
				if (table[i - 1][j]) {
					table[i][j] = true;
					continue;
				}
				for (int k = 1; k <= item[i].second; k++) {
					if (j - (k * item[i].first) < 1)break;
					if (table[i - 1][j - (k * item[i].first)]) {
						table[i][j] = true;
					}
				}
			}
		}

		cout << table[itemCount][totalV] << endl;

	}


}