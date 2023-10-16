#include <iostream>
#include<vector>
#include <queue>

using namespace std;

class SHARK {
public:
	int S = 0;
	int D = 0;
	int size = 0;
	SHARK() {};
	SHARK(int s,int d,int ss) {
		this->S = s;
		this->D = d;
		this->size = ss;
	}

	void changeDIR() {
		if (D == 1) D = 2;
		else if (D == 2) D = 1;
		else if (D == 3) D = 4;
		else if (D == 4) D = 3;
	}
};

void update_tile(SHARK& b,SHARK a) {
	if (b.size == 0|| b.size < a.size) b = a;
}

int main() {
	int R, C, M;
	cin >> R >> C >> M;
	vector<vector<SHARK>> table(R, vector<SHARK>(C));
	for (int i = 0; i < M; i++) {
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		SHARK temp(s,d,z);
		table[r - 1][c - 1]=temp;
	}

	int manX = -1;
	int result = 0;
	while (manX < C-1) {
		manX++;

		/*for (auto a : table) {
			for (auto b : a) {
				cout << b.size << " ";
			}
			cout << endl;
		}
		cout << endl;*/


		for (int i = 0; i < R; i++) {
			if (table[i][manX].size!=0) {
				result += table[i][manX].size;
				table[i][manX]=SHARK();
				break;
			}
		}

		vector<vector<SHARK>> temp(R, vector<SHARK>(C));
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (table[i][j].size==0) continue;
				int speed = table[i][j].S;
				
				if (table[i][j].D == 1 && i == 0) table[i][j].D = 2;
				if (table[i][j].D == 2 && i == R - 1) table[i][j].D = 1;
				if (table[i][j].D == 3 && j == C - 1) table[i][j].D = 4;
				if (table[i][j].D == 4 && j == 0) table[i][j].D = 3;
				int dir = table[i][j].D;
				if (dir == 1) {
					if (i >= speed) update_tile(temp[i - speed][j], table[i][j]);
					else {
						speed -= i;
						if ((speed / (R-1)) % 2 == 0) {
							table[i][j].changeDIR();
							
							update_tile(temp[speed % (R - 1)][j], table[i][j]);
						}
						else {
							update_tile(temp[(R - 1) - (speed % (R - 1))][j], table[i][j]);
						}
					}
				}
				else if (dir == 2) {
					if (R-1-i >= speed)update_tile(temp[i + speed][j], table[i][j]);
					else {
						speed -= R - 1 - i;
						if ((speed / (R - 1)) % 2 == 0) {
							table[i][j].changeDIR();
							update_tile(temp[(R - 1) - (speed % (R - 1))][j], table[i][j]);
						}
						else {
							update_tile(temp[speed % (R - 1)][j], table[i][j]);
						}
					}
				}
				else if (dir == 3) {
					if (C - 1 - j >= speed)update_tile(temp[i][j + speed], table[i][j]);
					else {
						speed -= C - 1 - j;
						if ((speed / (C - 1)) % 2 == 0) {
							table[i][j].changeDIR();
							update_tile(temp[i][(C - 1) - (speed % (C - 1))], table[i][j]);
						}
						else {
							update_tile(temp[i][speed % (C - 1)], table[i][j]);
						}
					}
				}
				else {
					if (j >= speed) update_tile(temp[i][j - speed], table[i][j]);
					else {
						speed -= j;
						if ((speed / (C - 1)) % 2 == 0) {
							table[i][j].changeDIR();
							update_tile(temp[i][speed % (C - 1)], table[i][j]);
						}
						else {
							update_tile(temp[i][(C - 1) - (speed % (C - 1))], table[i][j]);
						}
					}
				}
			}
		}
		table = temp;
	}
	cout << result << endl;
}
