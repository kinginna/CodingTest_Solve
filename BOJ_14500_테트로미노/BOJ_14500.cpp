#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int px[4] = { 0,0,-1,1 };
int py[4] = { 1,-1,0,0 };
 
vector<vector<int>> table;
int N, M;

int maxV[501][501] = { 0, };
bool visited[501][501] = { false, };
int maxValue = 0;
void DFS(int count,int V,int Y,int X) {
	if (count == 4) {
		maxValue = max(maxValue, V);
		return;
	} 

	for (int i = 0; i < 4; i++) {
		int ny = Y + py[i];
		int nx = X + px[i];
		if (ny < 0 || ny >= N || nx < 0 || nx >= M|| visited[ny][nx]) continue;
		visited[ny][nx] = true;
		DFS(count + 1, V + table[ny][nx], ny, nx);
		visited[ny][nx] = false;
	}

	if (count == 1) {
		for (int i = 0; i < 4; i++) {
			int tempV = V;
			for (int j = 0; j < 4; j++) {
				if (i == j) continue;
				int ny = Y + py[j];
				int nx = X + px[j];
				if (ny < 0 || ny >= N || nx < 0 || nx >= M) break;
				tempV += table[ny][nx];
			}
			maxValue = max(maxValue, tempV);
		}
	}
}

int main() {
	
	cin >> N >> M;
	table = vector<vector<int>>(N, vector<int>(M, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> table[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = true;
			DFS(1, table[i][j], i,j);
			visited[i][j] = false;
		}
	}

	cout << maxValue;
}