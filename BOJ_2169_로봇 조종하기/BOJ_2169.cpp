#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, M;

int py[3] = { 1,0,0 };
int px[3] = { 0,1,-1 };

vector<vector<int>> map_data;
vector<vector<vector<int>>> DP(vector<vector<vector<int>>>(3,vector<vector<int>>(1001, vector<int>(1001, -999999999))));

bool visited[1001][1001] = { false, };


int get_DP(int posX,int posY,int dir) {
	if (DP[dir][posY][posX] != -999999999) return DP[dir][posY][posX];
	for (int i = 0; i < 3; i++) {
		int nY = posY + py[i];
		int nX = posX + px[i];
		if (nY < 0 || nY >= N || nX < 0 || nX >= M || visited[nY][nX]) continue;
		visited[nY][nX] = true;
		DP[dir][posY][posX] = max(DP[dir][posY][posX], get_DP(nX, nY,i)+map_data[posY][posX]);
		visited[nY][nX] = false;
	}
	return DP[dir][posY][posX];
}

int main() {
	cin >> N >> M;
	visited[0][0] = true;
	map_data = vector<vector<int>>(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin>>map_data[i][j];
		}
	}
	DP[0][N - 1][M - 1] = map_data[N - 1][M - 1];
	DP[1][N - 1][M - 1] = map_data[N - 1][M - 1];
	DP[2][N - 1][M - 1] = map_data[N - 1][M - 1];
	cout << get_DP(0, 0,0);



}