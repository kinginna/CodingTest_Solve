#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;
int N;
vector<vector<int>> table;

int minDiff = 999999999;
void DFS(vector<int> list,int cur) {
	if (list.size() == N / 2) {
		int idx = 0;
		int list_score = 0;
		int other_score = 0;
		vector<int> other_list;
		for (int i = 0; i < N; i++){
			if (idx<N/2 && list[idx] == i) {
				idx++;
				continue;
			}
			other_list.push_back(i);

		}

		for (int i = 0; i < list.size(); i++) {
			for (int j = 0; j < list.size(); j++) {
				if (i == j) continue;
				list_score += table[list[i]][list[j]];
			}
		}
		for (int i = 0; i < other_list.size(); i++) {
			for (int j = 0; j < other_list.size(); j++) {
				if (i == j) continue;
				other_score += table[other_list[i]][other_list[j]];
			}
		}

		minDiff = min(minDiff, abs(other_score - list_score));

		return;



	}
	for (int i = cur + 1; i < N; i++) {
		list.push_back(i);
		DFS(list, i);
		list.pop_back();
 	}

}

int main() {
	cin >> N;
	table = vector<vector<int>>(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> table[i][j];
		}
	}
	vector<int> list;

	DFS(list, -1);

	printf("%d", minDiff);
	
}