#include <iostream>
#include <vector>

using namespace std;

int N, M;
int table[50][50] = { 0, };

int minDist = 999999999;
vector<pair<int, int>> chickens;
vector<pair<int, int>> homes;
void DFS(int cur,vector<pair<int,int>> selected) {
	if (selected.size() == M) {
		int totalScore = 0;
		for (int i = 0; i < homes.size(); i++) {
			int score=99999999;
			for (int j = 0; j < selected.size(); j++) {
				score = min(score, abs(selected[j].first - homes[i].first) + abs(selected[j].second - homes[i].second));
			}
			totalScore += score;
		}
		minDist = min(minDist, totalScore);
		return;
	}

	for (int i = cur; i < chickens.size(); i++) {
		selected.push_back(chickens[i]);
		DFS(i + 1, selected);
		selected.pop_back();
	}

}

int main() {
	cin >> N >> M;
	
	int chicken_count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> table[i][j];
			if (table[i][j] == 2) {
				chickens.push_back({ i,j });
				chicken_count++;
			}
			else if (table[i][j] == 1) {
				homes.push_back({ i,j });
			}

		}
	}

	M = min(M, chicken_count);
	DFS(0, vector<pair<int, int>>());
	cout << minDist << endl;
}