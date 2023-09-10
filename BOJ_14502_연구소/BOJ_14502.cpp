#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
vector<vector<int>> table;
int emptySize = 0;
int maxV = 0;
int py[4] = { 0,0,-1,1 };
int px[4] = { -1,1,0,0 };
int t = 0;
 void DFS(int count, int y, int x) {
	if (count == 3) {
		bool visited[9][9] = { false, };
		vector<vector<int>> temp = table;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (temp[i][j] != 2) continue;
				if (visited[i][j]) continue;
				queue<pair<int, int>> Q;
				Q.push({ i,j });
				visited[i][j] = true;
				while (!Q.empty()) {
					int y = Q.front().first;
					int x = Q.front().second;
					Q.pop();

					for (int k = 0; k < 4; k++) {
						int ny = y + py[k];
						int nx = x + px[k];
						if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx]|| temp[ny][nx]==1) {
							continue;
						}

						visited[ny][nx] = true;
						temp[ny][nx] = 2;
						Q.push({ ny,nx });
					}
				}
			}
		}

		int virusCount = 0;
		for (auto a : temp) {
			for (auto b : a) {
				if (b == 0) virusCount++;
			}
		}

		maxV = max(maxV,virusCount);

		return;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (i < y && j < x) continue;
			if (table[i][j] != 0) continue;
			table[i][j] = 1;
			DFS(count + 1, i, j);
			table[i][j] = 0;
		}
	}

}

int main() {
	cin >> N >> M;
	table = vector<vector<int>>(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			
			cin >> table[i][j];
			if (table[i][j] == 0) emptySize++;
		}
	}

	DFS(0,0,0);
	cout << maxV << endl;
}