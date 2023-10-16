#include <vector>

#include <iostream>

using namespace std;
int N;
vector<vector<bool>> table(101, vector<bool>(101, false));

vector<vector<bool>> get_curve(int x,int y,int d,int g) {
	vector < vector<bool >> temp(101, vector<bool>(101, false));
	int centorX = x;
	int centorY = y;
	temp[y][x] = true;
	if (d == 0)temp[y][x + 1] = true,centorX++;
	else if (d == 1) temp[y - 1][x] = true,centorY--;
	else if (d == 2) temp[y][x - 1] = true,centorX--;
	else temp[y + 1][x] = true,centorY++;

	int countG = 0;
	
	while (countG < g) {
		countG++;
		vector < vector<bool >> rotate(101, vector<bool>(101, false));
		int Wy = centorY - centorX;
		int Wx = centorX - (100 - centorY);
		for (int i = 0; i < 101; i++) {
			for (int j = 0; j < 101; j++) {
				if(temp[i][j])rotate[j + Wy][(100 - i) + Wx] = temp[i][j];
			}
		}
		int tempX = centorX;
		centorX = (100 - y) + Wx;
		centorY = x + Wy;
		for (int i = 0; i < 101; i++) {
			for (int j = 0; j < 101; j++) {
				if (rotate[i][j]) temp[i][j] = true;
			}
		}
	}

	return temp;

}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		vector<vector<bool>> curve=get_curve(x, y, d, g);
		for (int i = 0; i < 101; i++) {
			for (int j = 0; j < 101; j++) {
				if (curve[i][j]) table[i][j] = true;
			}
		}

		

	}

	int count = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (table[i][j] && table[i + 1][j] && table[i][j + 1] && table[i + 1][j + 1]) {
				count++;
			}
		}
	}
	cout << count;
}

