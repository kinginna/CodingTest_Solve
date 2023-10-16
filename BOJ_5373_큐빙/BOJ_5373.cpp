#include<iostream>
#include <vector>

using namespace std;
class SIDE {
private:

public:
	char side[3][3];
	SIDE() {};
	SIDE(char init_char) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				side[i][j] = init_char;
			}
		}
	}
	char** get_topside() {
		char** arr = new char* [3];
		arr[0] = &side[0][0];
		arr[1] = &side[0][1];
		arr[2] = &side[0][2];
		return arr;
	}
	char** get_downside() {
		char** arr = new char* [3];
		arr[0] = &side[2][0];
		arr[1] = &side[2][1];
		arr[2] = &side[2][2];
		return arr;
	}
	char** get_leftside() {
		char** arr = new char* [3];
		arr[0] = &side[0][0];
		arr[1] = &side[1][0];
		arr[2] = &side[2][0];
		return arr;
	}
	char** get_rightside() {
		char** arr = new char* [3];
		arr[0] = &side[0][2];
		arr[1] = &side[1][2];
		arr[2] = &side[2][2];
		return arr;
	}
	void rotate(char dir) {
		char temp[3][3];
		if (dir == '+') {  //시계방향 회전
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					temp[j][2 - i] = side[i][j];
				}
			}
		}
		else {
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					temp[2 - j][i] = side[i][j];
				}
			}
		}

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				side[i][j] = temp[i][j];
			}
		}

	}
	~SIDE() {
	}
};

class CUBE {
private:

public:
	SIDE top = SIDE('w');
	SIDE front = SIDE('r');
	SIDE down = SIDE('y');
	SIDE back = SIDE('o');
	SIDE left = SIDE('g');
	SIDE right = SIDE('b');

	void print_top() {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << top.side[i][j];
			}
			cout << endl;
		}
	}
	void move(char** side1, char** side2) {
		*side2[0] = *side1[0];
		*side2[1] = *side1[1];
		*side2[2] = *side1[2];
	}

	void move_side(char** side1, char** side2, char** side3, char** side4) {
		char temp[3] = { *side4[0],*side4[1], *side4[2] };

		move(side3, side4);
		move(side2, side3);
		move(side1, side2);


		*side1[0] = temp[0];
		*side1[1] = temp[1];
		*side1[2] = temp[2];

	}

	void rotate_CUBE(string order) {
		char dir1 = order[0];
		char dir2 = order[1];
		if (dir1 == 'L') {
			this->left.rotate(dir2);
			if (dir2 == '-') move_side(front.get_leftside(), top.get_leftside(), back.get_leftside(), down.get_leftside());
			else move_side(front.get_leftside(), down.get_leftside(), back.get_leftside(), top.get_leftside());
		}
		else if (dir1 == 'U') {
			this->top.rotate(dir2);
			char* temp[3] = { &back.side[2][2],&back.side[2][1],&back.side[2][0] };
			if (dir2 == '-') move_side(front.get_topside(), right.get_topside(), temp, left.get_topside());
			else move_side(front.get_topside(), left.get_topside(), temp, right.get_topside());
		}
		else if (dir1 == 'D') {
			this->down.rotate(dir2);
			char* temp[3] = { &back.side[0][2],&back.side[0][1],&back.side[0][0] };
			if (dir2 == '-') move_side(front.get_downside(), left.get_downside(), temp, right.get_downside());
			else move_side(front.get_downside(), right.get_downside(), temp, left.get_downside());
		}
		else if (dir1 == 'F') {
			this->front.rotate(dir2);
			char* top_down[3] = { &top.side[2][2],&top.side[2][1] ,&top.side[2][0] };
			char* right_left[3] = { &right.side[2][0],&right.side[1][0] ,&right.side[0][0] };
			if (dir2 == '-') move_side(top_down, left.get_rightside(), down.get_topside(), right_left);
			else move_side(top_down, right_left, down.get_topside(), left.get_rightside());
		}
		else if (dir1 == 'B') {
			this->back.rotate(dir2);
			char* down_down[3] = { &down.side[2][2],&down.side[2][1] ,&down.side[2][0] };
			char* left_left[3] = { &left.side[2][0],&left.side[1][0] ,&left.side[0][0] };
			if (dir2 == '-') move_side(top.get_topside(), right.get_rightside(), down_down, left_left);
			else move_side(top.get_topside(), left_left, down_down, right.get_rightside());
		}
		else if (dir1 == 'R') {
			this->right.rotate(dir2);
			if (dir2 == '-') move_side(front.get_rightside(), down.get_rightside(), back.get_rightside(), top.get_rightside());
			else move_side(front.get_rightside(), top.get_rightside(), back.get_rightside(), down.get_rightside());
		}
	}


};

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int work_count;
		cin >> work_count;
		CUBE cube;
		for (int j = 0; j < work_count; j++) {
			string order;
			cin >> order;
			cube.rotate_CUBE(order);
		}
		cube.print_top();
	}

}
