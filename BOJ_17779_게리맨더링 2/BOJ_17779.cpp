#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<vector<int>> table(N, vector<int>(N, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> table[i][j];
		}
	}
	int count = 0;

	int result = 999999999;

	for (int i = 1; i < N - 2; i++) {
		for (int j =0; j < N - 2; j++) {
			for (int d1 = 1;  i-d1 >= 0 && d1 + j < N - 1; d1++) {
				for (int d2 = 1; i+d2 < N && d2 + d1 + j < N; d2++) {
					
					
					int w = 0;
					int minV = 999999999;
					int maxV = 0;
					vector<vector<int>> temp = table;
					int areaV = 0;
					for (int y = 0; y < i; y++) {
						if (y >= i - d1) w++;
						for (int x = 0; x <= j + d1-w;x++) {
							areaV += temp[y][x];
							temp[y][x] = 0;
						}
					}
					minV = min(minV, areaV);
					maxV = max(maxV, areaV);

					w = 0;
					areaV = 0;
					for (int y = 0; y <= i-d1+d2; y++) {
						if (y > i - d1) w++;
						for (int x = j+d1+1+w; x < N; x++) {
							areaV += temp[y][x];
							temp[y][x] =0;
						}
					}
					minV = min(minV, areaV);
					maxV = max(maxV, areaV);

					w = 0;
					areaV = 0;
					for (int y = i; y < N; y++) {
						if (y <= i + d2) w++;
						for (int x = 0; x < j+w-1; x++) {
							areaV += temp[y][x];
							temp[y][x] = 0;
						}
					}
					minV = min(minV, areaV);
					maxV = max(maxV, areaV);

					w = 0;
					areaV = 0;
					for (int y =(i + d2 - d1)+1; y < N; y++) {
						if (y <= i + d2+1) w++;
						for (int x = j+d2+d1+1-w; x < N; x++) {
							areaV += temp[y][x];
							temp[y][x] = 0;
						}
					}
					minV = min(minV, areaV);
					maxV = max(maxV, areaV);

					areaV = 0;
					for (auto a : temp) {
						for (auto b : a) {
							areaV += b;
						}
						
					}


					minV = min(minV, areaV);
					maxV = max(maxV, areaV);
					result = min(result, maxV - minV);

				}
			}
		}
	}
	cout << result;
}