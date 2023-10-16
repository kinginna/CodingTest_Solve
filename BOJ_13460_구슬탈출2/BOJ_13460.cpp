#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int py[4] = { 0,0,-1,1 };
int px[4] = { 1,-1,0,0 };

int N, M;
int goalX, goalY;

struct BALL {
	int RedBallX;
	int RedBallY;
	int BlueBallX;
	int BlueBallY;
	int Cost;
};

vector<vector<char>> table;
bool visited[10][10][10][10] = { false, };//ry,rx,by,bx
int answer = 99999;
bool check_RedBallMoveFirst(int py, int px, BALL ball) {
	while (true) {
		ball.RedBallX += px;
		ball.RedBallY += py;
		if (ball.RedBallY < 0 || ball.RedBallY >= N || ball.RedBallX < 0 || ball.RedBallX >= M || table[ball.RedBallY][ball.RedBallX] == '#') break;
		if (ball.RedBallY == ball.BlueBallY && ball.BlueBallX == ball.RedBallX) {
			return false;
		}
	}
	return true;
}

bool moveBall(int& Y,int& X,int py,int px,int blockY,int blockX) {
	bool isGoal=false;
	while (true) {
		int nY = Y + py;
		int nX = X + px;
		
		if (nY < 0 || nY >= N || nX < 0 || nX >= M || table[nY][nX] == '#'||(nY==blockY && nX==blockX)) break;
		if (table[nY][nX] == 'O') {
			Y = -1;
			X = -1;
			return true;
		} 
		Y = nY;
		X = nX;
	}
	return isGoal;
}

int main() {
	cin >> N >> M;
	BALL firstBall = { 0,0,0,0,0 };
	table= vector<vector<char>>(N, vector<char>(M, '.'));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin>>table[i][j];
			if (table[i][j] == 'O') goalX = j, goalY = i;
			if (table[i][j] == 'R') {
				firstBall.RedBallX=j, firstBall.RedBallY=i;
				table[i][j] = '.';
			}
			if (table[i][j] == 'B') {
				firstBall.BlueBallX = j, firstBall.BlueBallY = i;
				table[i][j] = '.';
			}
		}
	}

	queue<BALL> Q;
	Q.push({firstBall});
	visited[firstBall.RedBallY][firstBall.RedBallX][firstBall.BlueBallY][firstBall.BlueBallX] = true;

	while (!Q.empty()) {
		BALL ball = Q.front();
		Q.pop();

		if (ball.Cost >= 10) break;
		for (int i = 0; i < 4; i++) {
			int nbX = ball.BlueBallX;
			int nbY = ball.BlueBallY;
			int nrX = ball.RedBallX;
			int nrY = ball.RedBallY;
			bool rGoal;
			bool bGoal;
			if (check_RedBallMoveFirst(py[i], px[i], ball)) {
				rGoal=moveBall(nrY, nrX, py[i], px[i], nbY, nbX);
				bGoal=moveBall(nbY, nbX, py[i], px[i], nrY, nrX);
			}
			else {
				bGoal = moveBall(nbY, nbX, py[i], px[i], nrY, nrX);
				rGoal = moveBall(nrY, nrX, py[i], px[i], nbY, nbX);
			}
			if (visited[nrY][nrX][nbY][nbX]) continue;
			if (bGoal) continue;
			if (rGoal) {
				answer = ball.Cost + 1;
				break;
			} 
			visited[nrY][nrX][nbY][nbX] = true;
			BALL nBall = { nrX,nrY,nbX,nbY,ball.Cost + 1 };
			Q.push(nBall);

		}
		if (answer != 99999) {
			cout << answer << endl;
			return 0;
		}

	}

	cout << -1 << endl;


}