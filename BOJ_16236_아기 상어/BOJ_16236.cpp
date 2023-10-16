#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int px[4] = { 0,0,-1,1 };
int py[4] = { 1,-1,0,0 };

class SHARK{
public:
	int size = 2;
	int food = 0;
	int x = 0;
	int y = 0;
};

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first < b.first) return true;
	else if (a.first == b.first) {
		return a.second < b.second;
	}
	else return false;
}

int main() {
	int N;
	cin >> N;
	SHARK shark;
	vector<vector<int>> table(N,vector<int>(N,0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> table[i][j];
			if (table[i][j] == 9) {
				table[i][j] = 0;
				shark.x = j;
				shark.y = i;
			}
		}

	}
	int result = 0;

	while (true) {
		queue<vector<int>> Q;
		bool visited[21][21] = { false, };
		visited[shark.y][shark.x] = true;
		Q.push({ shark.y,shark.x,0 });
		vector<pair<int, int>> possi;
		int post_dist = 0;
		while (!Q.empty()) {
			int x = Q.front()[1];
			int y = Q.front()[0];
			int dist = Q.front()[2];
			Q.pop();
			if (dist != post_dist) {
				if (possi.size() > 0) {
					break;
				}
				post_dist = dist;
			}
			for (int k = 0; k < 4; k++) {
				int ny = y + py[k];
				int nx = x + px[k];
				if (nx < 0 || nx >= N || ny < 0 || ny >= N || visited[ny][nx]) continue;
				if (table[ny][nx] > shark.size) continue;
				visited[ny][nx] = true;
				if (table[ny][nx]!=0&&table[ny][nx] < shark.size) possi.push_back({ny,nx});
				Q.push({ ny,nx,dist + 1 });
			}
		}
		if (possi.size() == 0) {
			break;
		}
		sort(possi.begin(), possi.end(), cmp);
		shark.y=possi[0].first;
		shark.x = possi[0].second;
		shark.food++;
		table[shark.y][shark.x] = 0;
		if (shark.food == shark.size) {
			shark.size++;
			shark.food = 0;
		}
		result += post_dist + 1;
	}
	cout << result << endl;
}