#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	stack<pair<int, int>> S;
	vector<int> result(N, 0);
	for (int i = 0; i < N; i++) {
		int V;
		cin >> V;
		while (!S.empty()) {
			if (S.top().first < V) S.pop();
			else {
				result[i] = S.top().second + 1;
				break;
			}
		}
		S.push({ V,i });
	}

	for (auto a : result) {
		cout << a << " ";
	}

}