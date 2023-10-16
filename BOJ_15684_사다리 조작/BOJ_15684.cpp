#include <iostream>
#include <vector>
#include <gmp.h>
using namespace std;

vector<vector<bool>> ladder;
int N, M, H;
int minV = 999999999;
bool check_ladder() {
	vector<int> goal(N,999999);
	bool result = true;
	for (int i = 0; i < N; i++) {
		int cur = i;
		for (int j = 0; j < H; j++) {
			if (cur == 0) {
				if (ladder[j][cur]) cur++;
			}
			else if (ladder[j][cur-1]) {
				cur--;
			}
			else if (cur  < N - 1 && ladder[j][cur]) {
				cur++;
			}
			
		}
		if (i != cur) return false;
	}
	return result;
}

void next(int *y,int *x) {
	if (*x + 1 < N - 1) *x+=1;
	else {
		*x = 0;
		*y+=1;
	}
}

void DFS(int max_way, int way_count, int y, int x) {
	if (minV == 0) return;
	if (check_ladder()) minV = min(minV, way_count);
	if (max_way == way_count) {
		return;
	}
	
	
	while (true) {
		if (x == N - 2 && y == H - 1) break;
		next(&y, &x);
		if (ladder[y][x]) continue;
		if (x + 1 < N - 1 && ladder[y][x + 1]) continue;
		if (x - 1 >= 0 && ladder[y][x - 1]) continue;
		ladder[y][x] = true;
		DFS(max_way, way_count + 1, y, x);
		ladder[y][x] = false;
	}
}


int main() {
	
	cin >> N >> M >> H;

	ladder = vector<vector<bool>>(H, vector<bool>(N-1, false));
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> y >> x;
		ladder[y - 1][x - 1] = true;
	}
	DFS(3, 0, 0, -1);
	if (minV != 999999999) {
		cout << minV << endl;
	}
	else cout << -1 << endl;
	
}