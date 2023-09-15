#include <iostream>
#include <vector>

using namespace std;

class GEAR {
public:
	vector<int> magnet;
	GEAR() {};
	GEAR(string mag) {
		magnet = vector<int>(8, 0);
		for (int i = 0; i < 8; i++) {
			if (mag[i] == '1') magnet[i] = 1;
		}
	}
	void rotate(int dir) {
		if (dir == -1) {
			int temp = magnet[0];
			for (int i = 0; i < 7; i++) {
				magnet[i] = magnet[i + 1];
			}
			magnet[7] = temp;
		}
		else {
			int temp = magnet[7];
			for (int i = 7; i >0; i--) {
				magnet[i] = magnet[i - 1];
			}
			magnet[0] = temp;
		}
	}
};


int main() {
	vector<GEAR> gear_list(4);
	for (int i = 0; i < 4; i++) {
		string input;
		cin >> input;
		gear_list[i] = GEAR(input);
	}
	int K;
	cin >> K;
	for (int i = 0; i < K; i++) {
		int main_gear, dir;
		cin >> main_gear >> dir;
		main_gear--;
		vector<pair<int, int>> todo;
		todo.push_back({ main_gear,dir });
		int right_dir = dir;
		for (int i = main_gear; i < 3; i++) {
			if (gear_list[i].magnet[2] == gear_list[i + 1].magnet[6]) break;
			right_dir *= -1;
			todo.push_back({ i + 1,right_dir});
		}
		int left_dir = dir;
		for (int i = main_gear; i > 0; i--) {
			if (gear_list[i].magnet[6] == gear_list[i - 1].magnet[2]) break;
			left_dir *= -1;
			todo.push_back({ i - 1,left_dir });
		}

		for (auto work : todo) {
			gear_list[work.first].rotate(work.second);
		}
	}

	int score = 0;
	if (gear_list[0].magnet[0] == 1) score += 1;
	if (gear_list[1].magnet[0] == 1) score += 2;
	if (gear_list[2].magnet[0] == 1) score += 4;
	if (gear_list[3].magnet[0] == 1) score += 8;
	cout << score << endl;

}