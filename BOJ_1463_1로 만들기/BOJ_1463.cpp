#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> DP(1000001, 999999999);
	DP[1] = 0;
	DP[2] = 1;
	DP[3] = 1;
	for (int i = 4; i < 1000001; i++) {
		DP[i] = DP[i - 1] + 1;
		if (i % 2 == 0) DP[i] = min(DP[i / 2] + 1,DP[i]);
		if(i%3==0)DP[i] = min(DP[i / 3] + 1, DP[i]);
	}
	int N;
	cin >> N;
	cout << DP[N];
}