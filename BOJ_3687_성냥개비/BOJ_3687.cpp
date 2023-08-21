#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

int stickCount[10] = { 6, 2,5,5,4,5,6,3,7,6 };

bool minCheck(string a, string b) {
	if (a.size() < b.size()) return true;
	else if (a.size() == b.size()) {
		for (int i = 0; i < a.size(); i++) {
			if (a[i] == b[i]) continue;
			if (a[i] < b[i]) return true;
			else return false;
		}
	}
	else return false;
	return true;
}


int main() {
	int T;
	cin >> T;

	vector<string> minDP(101, "99999999999999999999999999999999999999999999999999999999999");
	vector<string> maxDP(101, "0");
	minDP[2] = "1";
	maxDP[2] = "1";

	for (int i = 3; i < 101; i++) {
		if (i <= 7) {
			for (int j = 0; j < 10; j++) {
				if (stickCount[j] == i) {
					minDP[i] = to_string(j);
					break;
				}
			}
			continue;
		}

		string temp = "9999999999999999999999999999999999999999999999999999999999999";
		for (int j = 0; j < 10; j++) {

			if (minCheck(to_string(j) + minDP[i - stickCount[j]], temp)) {
				temp = to_string(j) + minDP[i - stickCount[j]];
			}
		}
		minDP[i] = temp;
	}

	//maxDP
	maxDP[2] = "1";
	maxDP[3] = "7";
	maxDP[4] = "11";
	for (int i = 5; i < 101; i++) {
		string temp = "0";
		for (int j = 0; j < 10; j++) {
			if (i - stickCount[j] <= 1) continue;
			if (minCheck(temp, to_string(j) + maxDP[i - stickCount[j]])) {
				temp = to_string(j) + maxDP[i - stickCount[j]];
			}
		}
		maxDP[i] = temp;
	}



	while (T--) {
		int num;
		cin >> num;
		if (num <= 7) {
			if (num == 6) cout << 6 << " " << maxDP[num] << endl;
			else cout << minDP[num] << " " << maxDP[num] << endl;
		}
		else {
			string temp = "99999999999999999999999999999999999999999999999999";
			for (int j = 1; j < 10; j++) {
				if (minCheck(to_string(j) + minDP[num - stickCount[j]], temp)) {
					temp = to_string(j) + minDP[num - stickCount[j]];
				}
			}
			cout << temp << " " << maxDP[num] << endl;
		}
	}
}


