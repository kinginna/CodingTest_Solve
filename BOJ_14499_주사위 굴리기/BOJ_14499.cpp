#include <iostream>
#include <vector>

using namespace std;

int py[4] = { 0,0,-1,1 };
int px[4] = { 1,-1,0,0 };

vector<vector<int>> update_dice( vector<vector<int>> d,int dir) {
	vector<vector<int>> result(4, vector<int>(3, 0 ));
	result = d;
	if (dir == 2) {
		result[1][1] = d[1][0];
		result[1][0] = d[3][1];
		result[1][2] = d[1][1];
		result[3][1] = d[1][2];
	}
	else if (dir == 1) {
		result[1][1] = d[1][2];
		result[1][0] = d[1][1];
		result[1][2] = d[3][1];
		result[3][1] = d[1][0];
	}
	else if (dir == 3) {
		result[0][1] = d[3][1];
		result[1][1] = d[0][1];
		result[2][1] = d[1][1];
		result[3][1] = d[2][1];
	}
	else {
		result[0][1] = d[1][1];
		result[1][1] = d[2][1];
		result[2][1] = d[3][1];
		result[3][1] = d[0][1];
	}

	return result;

}
  
int main() {
	int N, M, x, y, K;
	cin>>N>> M>> y>> x>> K;

	vector<vector<int>> table(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> table[i][j];
		}
	}
	vector<vector<int>> my_dice(4, vector<int>(3,0));
 	for (int i = 0; i < K; i++) {
		int order;
		cin >> order;
		int nx = x + px[order - 1];
		int ny = y + py[order - 1];
		if (nx < 0 || nx >= M || ny < 0 || ny >= N)continue;
		my_dice = update_dice(my_dice,order);

		if (table[ny][nx] == 0) {
			table[ny][nx] = my_dice[1][1];
		}
		else {
			my_dice[1][1]= table[ny][nx];
			table[ny][nx] = 0;
		}
		
		cout << my_dice[3][1]<< endl;
		x = nx;
		y = ny;
	}

}