#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int>a, pair<int, int> b) {
	if (a.second < b.second) return true;
	else if (a.second == b.second) {
		if (a.first < b.first) return true;
		else if (a.first == b.first) return true;
		else return false;
	}
	else return false;
}

vector<int> sortVector(vector<int> A) {
	map<int, int> M;
	set<int> S;
	vector<pair<int, int>> temp;
	vector<int> result;
	for (int i = 0; i < A.size(); i++) {
		if (A[i] == 0) continue;
		S.insert(A[i]);
		M[A[i]]++;
	}

	for (auto a : S) {
		temp.push_back({ a,M[a] });
	}

	sort(temp.begin(), temp.end(), cmp);
	for (auto a : temp) {
		result.push_back(a.first);
		result.push_back(a.second);
	}

	if (result.size() > 100) {
		result.erase(result.begin() + 100, result.end());
	}

	return result;
}

int main() {
	int r, c, k;
	cin >> r >> c >> k;
	vector<vector<int>> table(3, vector<int>(3));
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> table[i][j];
		}
	}


	

	int time = 0;
	while (time<101 ) {
		if (table.size() >= r && table[0].size() >= c && table[r - 1][c - 1] == k) break;
		time++;
		int largest = 0;
		
		if (table.size() >= table[0].size()) {//R연산
			
			for (int i = 0; i < table.size(); i++) {
				table[i] = sortVector(table[i]);
				largest = max((int)table[i].size(), largest);
			}

			for (int i = 0; i < table.size(); i++) {
				table[i].insert(table[i].end(), largest - table[i].size(),0 );
			}

		}
		else {//C 연산
			vector<vector<int>> sorted_table(table.size(), vector<int>(table[0].size(), 0));
			for (int i = 0; i < table[0].size(); i++) {
				vector<int> temp;
				for (int j = 0; j < table.size(); j++) {
				
					temp.push_back(table[j][i]);
				}
				temp = sortVector(temp);
				while (temp.size() > sorted_table.size()) {
					sorted_table.push_back(vector<int>(table[0].size(), 0));
				}

				for (int j = 0; j < temp.size(); j++) {
					sorted_table[j][i] = temp[j];
				}
			}
			table = sorted_table;
		}

	}
	if (time == 101) cout << -1;
	else cout << time << endl;
	
}