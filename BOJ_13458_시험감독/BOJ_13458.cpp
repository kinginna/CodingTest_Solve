#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> list(N,0);

	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}

	int B, C;
	long long result = N;
	cin >> B >> C;
	for (auto a : list) {
		if (a - B <= 0) continue;
		result += (a - B) / C;
		if ((a - B) % C != 0) result++;
	}

	cout << result << endl;
	

}