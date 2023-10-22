#include <iostream>
#include <vector>
#include <map>
using namespace std;

int py[4] = { 0,0,-1,1 };
int px[4] = { 1,-1,0,0 };

struct GADGET {
	int dir;
	int num;
	GADGET(int d, int n) {
		
		dir = d;
		num = n;
	}
};

struct PLATE {
	int color;
	PLATE(int c) {
		color = c;
	}
	vector<GADGET> gadget_list;
};

map<int, pair<int, int>> gadget_pos;

int changeDIR(int num) {
	if (num == 0) return  1;
	else if (num == 1) return 0;
	else if (num == 2) return 3;
	else if (num == 3) return 2;
}

int main() {
	int N,K;
	cin >> N >> K;
	vector<vector<PLATE>> table(N + 2, vector<PLATE>(N + 2, 2));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int color;
			cin >> color;
			table[i][j].color = color;
		}
	}

	for (int i = 0; i < K; i++) {
		int R, C, D;
		cin >> R >> C >> D;
		table[R][C].gadget_list.push_back(GADGET( D-1,i + 1 ));
		gadget_pos[i + 1] = { R,C };
	}
	int count = 0;
	while (count < 1001) {
		count++;
		bool gameEND = false;
		for (int i = 0; i < K; i++) {
			int y = gadget_pos[i + 1].first;
			int x = gadget_pos[i + 1].second;
			
			int cur = 0;
			int dir = 0;
			for (int j = 0; j < table[y][x].gadget_list.size(); j++) {
				if (table[y][x].gadget_list[j].num == i+1) {
					cur = j;
					break;
				} 
			}
			vector<GADGET> temp;
			for (int j = cur; j < table[y][x].gadget_list.size(); j++) {
				temp.push_back(table[y][x].gadget_list[j]);
			}
			dir = table[y][x].gadget_list[cur].dir;
			table[y][x].gadget_list.erase(table[y][x].gadget_list.begin() + cur, table[y][x].gadget_list.end());
			
			int ny = y + py[dir];
			int nx = x + px[dir];

			if (table[ny][nx].color == 0) {
				for (int j = 0; j < temp.size(); j++) {
					table[ny][nx].gadget_list.push_back(temp[j]);
					gadget_pos[temp[j].num] = { ny,nx };
				}
				if (table[ny][nx].gadget_list.size() > 3) gameEND = true;
			}
			else if (table[ny][nx].color == 1) {
				for (int j = temp.size()-1; j >= 0; j--) {
					table[ny][nx].gadget_list.push_back(temp[j]);
					gadget_pos[temp[j].num] = { ny,nx };
				}
				if (table[ny][nx].gadget_list.size() > 3) gameEND = true;
			}
			else {
				dir = changeDIR(dir);
				int nny = y + py[dir];
				int nnx = x + px[dir];
				temp[0].dir = dir;
				if (table[nny][nnx].color == 2) {
					for (int j = 0; j < temp.size(); j++) {
						table[y][x].gadget_list.push_back(temp[j]);
					}
					if (table[y][x].gadget_list.size() > 3) gameEND = true;
				}
				else {
					if (table[nny][nnx].color == 0) {
						for (int j = 0; j < temp.size(); j++) {
							table[nny][nnx].gadget_list.push_back(temp[j]);
							gadget_pos[temp[j].num] = { nny,nnx };
						}
					}
					else {
						for (int j = temp.size() - 1; j >= 0; j--) {
							table[nny][nnx].gadget_list.push_back(temp[j]);
							gadget_pos[temp[j].num] = { nny,nnx };
						}
					}
					if (table[nny][nnx].gadget_list.size() > 3) gameEND = true;
				}
			}

			if (gameEND) break;


		}
		if (gameEND) break;
	}
	if (count >= 1001) cout << -1;
	else cout << count;

}