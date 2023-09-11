#include <iostream>
#include<vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> list;
int p, s, m, d;
int N;
int minV = 1500000000;
int maxV = -1500000000;

struct oper {
	int plus = 0;
	int subtract = 0;
	int multiple=0;
	int divied = 0;
};

int calculrate(string expression) {
	int num = list[0];
	for (int i = 0; i < expression.size(); i++) {
		if (expression[i] == '+') num += list[i + 1];
		if (expression[i] == '-') num -= list[i + 1];
		if (expression[i] == '*') num *= list[i + 1];
		if (expression[i] == '/') num /= list[i + 1];
	}

	return num;
}


void DFS(int count, string expression, oper OPER) {
	if (count == N) {
		int num = calculrate(expression);
		minV = min(minV, num);
		maxV = max(maxV, num);
		return;
	}

	if (OPER.plus > 0) {
		oper temp = OPER;
		temp.plus--;
		DFS(count + 1, expression + "+" , temp);
	}
	if (OPER.subtract > 0) {
		oper temp = OPER;
		temp.subtract--;
		DFS(count + 1, expression + "-" , temp);
	}
	if (OPER.multiple > 0) {
		oper temp = OPER;
		temp.multiple--;
		DFS(count + 1, expression + "*" , temp);
	}
	if (OPER.divied > 0) {
		oper temp = OPER;
		temp.divied--;
		DFS(count + 1, expression + "/" , temp);
	}
}


int main() {
	cin >> N;
	list=vector<int>(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}

	cin >> p >> s >> m >> d;

	oper Oper = { p,s,m,d };

	DFS(1, "", Oper);
	cout << maxV << endl;
	cout << minV << endl;
}