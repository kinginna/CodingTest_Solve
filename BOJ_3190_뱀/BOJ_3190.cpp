#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int py[4] = { 0,1,0,-1 };
int px[4] = { 1,0,-1,0 };
int N, K;
void update_MAP(vector<vector<int>>& table,int dist) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (table.at(i).at(j) <= 0) continue;
			if (table.at(i).at(j) + 1 > dist) {
				table.at(i).at(j) =0;
			}
			else {
				table.at(i).at(j) +=1;
			}
		}
	}
}

int main() {
	
	cin >> N>>K;
	vector<vector<int>> table(N, vector<int>(N, 0));
	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> x >> y;
		table[x-1][y-1] = -1;
	}

	int L;
	cin >> L;
	queue<pair<int, char>> Q; //time,dir

	for(int i = 0; i < L; i++) {
		int X;
		char C;
		cin >> X >> C;
		Q.push({ X,C });
	}
	int time = 0;
	int dir = 0;
	int Y = 0;
	int X = 0;
	int distance = 1;
	table[0][0] = 1;
	while (true) {
		time++;
		

		Y = Y + py[dir];
		X = X + px[dir];
		if (Y < 0 || Y >= N || X < 0 || X >= N || table[Y][X]>0) break;
		if (table[Y][X] == -1) {
			distance++;
			table[Y][X] = 0;
		}
		update_MAP(table, distance);
		table[Y][X] = 1;
		if (!Q.empty()&&Q.front().first == time) {
			if (Q.front().second == 'L') {
				dir--;
			}
			else {
				dir++;
			}
			dir = dir == -1 ? 3 : dir;
			dir = dir == 4 ? 0 : dir;
			Q.pop();
		}

	}
	cout << time;

}