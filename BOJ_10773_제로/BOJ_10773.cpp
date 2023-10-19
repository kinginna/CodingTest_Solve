#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int K;
	cin >> K;
	stack<int> S;
	for (int i = 0; i < K; i++) {
		int V;
		cin >> V;
		if (V == 0) {
			S.pop();
		}
		else {
			S.push(V);
		}
	}


	int result = 0;
	while (!S.empty()) {
		result += S.top();
		S.pop();
	}
	cout << result;
}