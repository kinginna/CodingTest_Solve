#include<vector>
#include<queue>
#include <iostream>
#include <algorithm>

using namespace std;

int px[8] = { 0,1,1,1,0,-1,-1,-1 };
int py[8] = { -1,-1,0,1,1,1,0,-1 };

class LAND {
public:
	int food=5;
	vector<int> tree;

	void feed() {
		//sort(tree.begin(), tree.end(), less<>());
		int tempFood = 0;
		for (int i = 0; i < tree.size(); i++) {
			if (tree[i] > food) {
				for (int j = i; j < tree.size(); j++) {
					tempFood += tree[j] / 2;
				}
				tree.erase(tree.begin() + i, tree.end());
				break;
			}
			food -= tree[i];
			tree[i]++; 
		}
		food += tempFood;
	}

	int get_adult_tree() {
		int count = 0;

		for (int i = 0; i < tree.size(); i++) {
			if (tree[i] % 5 == 0) count++;
		}
		return count;
	}

};


int main() {
	int N, M, K;
	cin >> N >> M >> K;
	vector<vector<LAND>> area(N, vector<LAND>(N));
	vector<vector<int>> S2D2(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> S2D2[i][j];
		}
	}

	for (int i = 0; i < M; i++) {
		int x, y, age;
		cin >> x >> y >> age;
		area[x-1][y-1].tree.push_back(age);
	}

	for (int t = 0; t < K; t++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				area[i][j].feed();
				area[i][j].food += S2D2[i][j];
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				int adultTree = area[i][j].get_adult_tree();
				if (adultTree == 0) continue;
				for (int u = 0; u < 8; u++) {
					int ny = i + py[u];
					int nx = j + px[u];
					if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
					for (int seq = 0; seq < adultTree; seq++) {
						area[ny][nx].tree.insert(area[ny][nx].tree.begin(),1);
					}
				}
			}
		}

	}
	int result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			result+=area[i][j].tree.size();
		}
	}

	cout << result << endl;
}

