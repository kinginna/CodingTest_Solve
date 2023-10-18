#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int py[4] = { 0,0,1,-1 };
int px[4] = { -1,1,0,0 };
int minTime = 999999999;
int N, M;
int empty_roomCount = 0;
vector<pair<int, int>> virus_pos;
vector<vector<int>> table;
void DFS(vector<pair<int,int>> virus_list,int idx) {
	if (virus_list.size() == M) {
		int roomCount = 0;
		bool visited[51][51] = { false, };
		queue<vector<int>> Q;
		for (auto a : virus_list) {
			Q.push({ a.first,a.second,0 });
			visited[a.first][a.second] = true;
		}

		while (!Q.empty()) {
			int Y = Q.front()[0];
			int X = Q.front()[1];
			int time = Q.front()[2];
			Q.pop();
			if (table[Y][X] == 0) roomCount++;
			if (time > minTime) break;
			if (empty_roomCount == roomCount) {
				minTime = min(minTime, time);
				break;
			}
			for (int k = 0; k < 4; k++) {
				int nY = Y + py[k];
				int nX = X + px[k];
				if (nY < 0 || nY >= N || nX<0 || nX>=N || table[nY][nX] == 1 || visited[nY][nX]) continue;
				visited[nY][nX] = true;
				Q.push({ nY,nX,time + 1 });
			}
		}

		return;
	}

	for (int i = idx; i < virus_pos.size(); i++) {
		virus_list.push_back(virus_pos[i]);
		DFS(virus_list, i + 1);
		virus_list.pop_back();
	}

}

int main() {
	
	cin >> N >> M;
	table= vector<vector<int>>(N, vector<int>(N, 0));
	
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> table[i][j];
			if (table[i][j] == 2) virus_pos.push_back({ i,j });
			if (table[i][j] == 0)empty_roomCount++;
		}
	}

	DFS(vector<pair<int, int>>(),0);
	

	if(minTime== 999999999)cout << -1 << endl;
	else cout << minTime << endl;

}