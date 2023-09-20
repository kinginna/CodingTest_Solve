#include <iostream>
#include <vector>

using namespace std;

int py[4] = { 0,-1,0,1 };
int px[4] = { -1,0,1,0 };

int N, M;

int minV = 999999999;

int count_CCTV = 0;
vector<vector<int>> table;

vector<vector<int>> drawLine(vector<vector<int>> temp, int y, int x, int dir) {
	int idx = 1;
	while (true) {
		int ny = y + (py[dir] * idx);
		int nx = x + (px[dir] * idx);
		if (ny < 0 || ny >= N || nx < 0 || nx >= M || table[ny][nx] == 6) break;
		if (temp[ny][nx] == 0) temp[ny][nx] = 7;
		idx++;
	}
	return temp;
}

void DFS(int count,int y,int x,vector<vector<int>> area) {
	if (count == count_CCTV) {
		int V = 0;
		for (auto a : area) {
			for (auto b : a) {
				if (b == 0) V++;
			}
		}
		minV = min(minV, V);
		return;
	}
 	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {

			if (i<y||(i <= y && j <= x)) continue;
			if (area[i][j] > 0 && area[i][j] < 6) {
				if (y == 3 && x == 2 && count == 7) cout << i << " " << j << " !!" << endl;
				if (area[i][j] == 1) {
					for (int k = 0; k < 4; k++) {
						vector<vector<int>> temp = drawLine(area,i,j,k);
						DFS(count + 1, i, j, temp);
					}
				}
				else if (area[i][j] == 2) {
					for (int k = 0; k < 2; k++) {
						vector<vector<int>> temp = drawLine(area, i, j, k);
						temp = drawLine(temp, i, j, k+2);
						DFS(count + 1, i, j, temp);
					}
				}
				else if (area[i][j] == 3) {
					for (int k = 0; k < 4; k++) {
						vector<vector<int>> temp = drawLine(area, i, j, k);
						temp = drawLine(temp, i, j, k + 1==4?0:k+1);
						DFS(count + 1, i, j, temp);
					}
				}
				else if (area[i][j] == 4) {
					for (int k = 0; k < 4; k++) {
						vector<vector<int>> temp = drawLine(area, i, j, k);
						temp = drawLine(temp, i, j, k + 1 == 4 ? 0 : k + 1);
						temp = drawLine(temp, i, j, k - 1 == -1 ? 3 : k - 1);
						DFS(count + 1, i, j, temp);
					}
				}
				else if(area[i][j]==5) {
					vector<vector<int>> temp = drawLine(area, i, j, 0);
					temp = drawLine(temp, i, j, 1);
					temp = drawLine(temp, i, j, 2);
					temp = drawLine(temp, i, j, 3);
					DFS(count + 1, i, j, temp);
				}
				return;
			}
			
		}
	}


}

int main() {
	cin >> N >> M;
	table = vector<vector<int>>(N, vector<int>(M, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> table[i][j];
			if (table[i][j] > 0 && table[i][j] < 6) count_CCTV++;
	 	}
	}
	DFS(0, -1, -1, table);
	cout << minV << endl;

}