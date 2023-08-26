#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	long long N, M;
	cin >> N >> M;
	vector<long long> dp(N+1, 99999999999999999);
	vector<vector<pair<long long, long long>>> graph(N + 1);

	dp[1] = 0;

	for (int i = 0; i < M; i++) {
		long long from, to;
		cin >> from >> to;
		graph[from].push_back({ to,i+1 });
		graph[to].push_back({ from,i + 1 });
	}

	priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<>> Q;
	Q.push({ 0,1 });
	while (!Q.empty()) {
		long long Node = Q.top().second;
		long long dist = Q.top().first;
		Q.pop();
		if (dist > dp[Node])continue;
		for (int i = 0; i < graph[Node].size(); i++) {
			long long NewNode = graph[Node][i].first;
			long long sequence= graph[Node][i].second+(M*(dist/M));
			long long NewDist;
			if (dist < sequence) {
				NewDist = sequence;
			}
			else {
				NewDist = dist + (sequence-dist)+M;
			}

			if (NewDist < dp[NewNode]) {
				dp[NewNode] = NewDist;
				Q.push({ dp[NewNode],NewNode });
			}

		}

	}
	cout << dp[N] << endl;

}