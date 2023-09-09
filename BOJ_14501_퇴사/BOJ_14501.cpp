#include<iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> DP(N+1, 0);
	vector<pair<int,int>> schedule(N+1);
	for (int i = 0; i < N; i++) {
		int T, P;
		cin >> T >> P;
		DP[i] = max(DP[max(i - 1, 0)], DP[i]);
		if (i + T > N) continue;
		DP[i + T] = max(DP[i + T], DP[i] + P);

	}

	cout << max(DP[N],DP[N-1]);

}