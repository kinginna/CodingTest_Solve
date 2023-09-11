#include <iostream>
#include <vector>
using namespace std;

int N, M;
int ry, rx, rd;
int py[4] = { -1,0,1,0 };
int px[4] = { 0,1,0,-1 };

int main() {
	cin >> N >> M;
	cin >> ry >> rx >> rd;

	vector<vector<int>> table(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++) { 
		for (int j = 0; j < M; j++) {
			cin >> table[i][j];
		}
	}
	int cleanCount = 0;
	while (true) {

		if (table[ry][rx] == 0) {
			cleanCount++;
			table[ry][rx] = 2;
		}

		bool isin_cleanArea = false;
		int newY;
		int newX;
		int tempDir = rd;
		for (int i = 0; i < 4; i++) {
			tempDir--;
			if (tempDir == -1) tempDir = 3;
			int ny = ry + py[tempDir];
			int nx = rx + px[tempDir];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M||table[ny][nx]==1)continue;
			if (table[ny][nx] == 2) continue;
			if (table[ny][nx] == 0) {
				isin_cleanArea = true;
				newY = ny;
				newX = nx;
				break;
			}
		}

		if (isin_cleanArea) {
			ry = newY;
			rx = newX;
			rd = tempDir;
		}
		else {
			int ny = ry - py[rd];
			int nx = rx - px[rd];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M || table[ny][nx] == 1) {
				break;
			}

			ry = ny;
			rx = nx;
		}

	}

	cout << cleanCount << endl;

}