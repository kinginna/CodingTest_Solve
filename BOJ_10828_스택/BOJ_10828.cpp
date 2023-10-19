#include <stack>
#include <iostream>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	stack<int> S;

	for (int i = 0; i < N; i++) {
		string order;
		cin >> order;
		int V;
		if (order == "push") {
			cin >> V;
			S.push(V);
		}
		else if (order == "pop") {
			if (S.size() == 0) cout << -1 << "\n";
			else {
				cout << S.top() << "\n";
				S.pop();
			}
		}
		else if (order == "size") {
			cout << S.size() << "\n";
		}
		else if (order == "empty") {
			cout << S.empty() << "\n";
		}
		else {
			if (S.size() == 0) cout << -1 << "\n";
			else {
				cout << S.top() << "\n";
			}
		}
	}
}