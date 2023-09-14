#include <iostream>
#include <vector>

using namespace std;
int N, L;
bool check_Road(vector<int> road) {
	vector<bool> stair(road.size(),false);

	for (int i = 0; i < road.size()-1; i++) {
		if (road[i] != road[i + 1]) {
			if (abs(road[i] - road[i + 1]) > 1) return false;
			if (road[i] < road[i + 1]) {
				if (i - (L - 1) < 0) return false;
				for (int j = i - (L - 1); j <= i; j++) {
					if (road[j] != road[i]) return false;
					if (stair[j]) return false;
				}
				for (int j = i - (L - 1); j <= i; j++) {
					stair[j] = true;
				}
				
			}
			else {
				if (i + L  >= N) return false;
				for (int j = i+1; j <= i + L; j++) {
					if (road[j] != road[i+1]) return false;
					if (stair[j]) return false;
				}
				for (int j = i+1; j <= i + L; j++) {
					stair[j] = true;
				}
			}

		}
	}
	return true;	

}
int main() {
	int result = 0;
	cin >> N>>L;
	vector<vector<int>> table(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> table[i][j];
		}
	}

	//check row


	for (int i = 0; i < N; i++) {
		vector<int> row(N);
		vector<int> col(N);
		for (int j = 0; j < N; j++) {
			row[j] = table[i][j];
			col[j] = table[j][i];
		}

		if (check_Road(row)) {
			result++;
		}
		if (check_Road(col)) {
			result++;
		}

	}



	cout << result << endl;
}