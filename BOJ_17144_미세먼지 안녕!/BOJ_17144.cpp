#include <iostream>
#include<vector>
using namespace std;

int py[4] = { 0,0,-1,1 };
int px[4] = { -1,1,0,0 };

int main() {
	int R, C, T;
	cin >> R >> C >> T;
	vector<vector<int>> ROOM(R, vector<int>(C));
	int cleanerY=-1;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> ROOM[i][j];
			if (ROOM[i][j] == -1&& cleanerY==-1) {
				cleanerY = i;
			}
		}
	}
	ROOM[cleanerY][0] = 0;
	ROOM[cleanerY+1][0] = 0;

	while (T--) {
		vector<vector<int>> add_dust(R, vector<int>(C,0));
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (ROOM[i][j] == 0) continue;
				int diffusion = 0;
				for (int k = 0; k < 4; k++) {
					int ny = i + py[k];
					int nx = j + px[k];
					if (nx < 0 || nx >= C || ny < 0 || ny >= R) continue;
					if ((nx == 0 && ny == cleanerY) || (nx == 0&& ny == cleanerY + 1)) continue;
					diffusion++;
					add_dust[ny][nx] += ROOM[i][j] / 5;
				}
				ROOM[i][j] = ROOM[i][j] - (diffusion * (int)(ROOM[i][j] / 5));
			}
		}

		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				ROOM[i][j]  +=add_dust[i][j];
			}
		}
		

		for (int i = cleanerY - 1; i > 0; i--) {
			ROOM[i][0] = ROOM[i - 1][0];
		}
		for (int i = 0; i < C - 1; i++) {
			ROOM[0][i] = ROOM[0][i + 1];
		}
		for (int i = 0; i < cleanerY; i++) {
			ROOM[i][C - 1] = ROOM[i + 1][C - 1];
		}
		for (int i = C - 1; i > 1; i--) {
			ROOM[cleanerY][i] = ROOM[cleanerY][i - 1];
		}
		ROOM[cleanerY][1] = 0;
		//아래쪽 공청기 순환

		for (int i = cleanerY+2; i < R-1; i++) {
			ROOM[i][0] = ROOM[i + 1][0];
		}
		for (int i = 0; i < C - 1; i++) {
			ROOM[R-1][i] = ROOM[R-1][i + 1];
		}
		for (int i = R-1; i > cleanerY+1; i--) {
			ROOM[i][C - 1] = ROOM[i - 1][C - 1];
		}
		for (int i = C - 1; i > 1; i--) {
			ROOM[cleanerY+1][i] = ROOM[cleanerY+1][i - 1];
		}
		ROOM[cleanerY+1][1] = 0;


	}

	int result = 0;
	for (auto a : ROOM) {
		for (auto b : a) {
			result+= b;
		}
	}
	cout << result;

}