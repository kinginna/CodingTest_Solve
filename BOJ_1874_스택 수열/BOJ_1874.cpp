#include <stack>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;
	stack<int> S;
	vector<int> list(N);
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
	int cur = 0;
	vector<char> result;
	bool is_possi = true;
	for (int i = 1; i < 100001; i++) {
		S.push(i);
		result.push_back('+');
		while (!S.empty() && cur<N&&S.top() == list[cur]) {
			cur++;
			S.pop();
			result.push_back('-');
		}
		if (cur == N) break;
		if (!S.empty()&& list[cur] < S.top()) {
			is_possi = false;
			break;
		}
	}

	if (is_possi) {
		for (auto a : result) {
			cout << a << "\n";
		}
	}
	else {
		cout << "NO" << endl;

	}

}
