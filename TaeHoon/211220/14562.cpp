#include <iostream>

using namespace std;

int result;

void dfs(int currentS, int currentT, int depth) {
	if (currentS >= currentT) {
		if (currentS == currentT && depth < result)
			result = min(depth, result);
		return ;
	}
	for (int i = 0; i < 2; i++) {
		if (i == 0) {
			dfs(currentS * 2, currentT + 3, depth + 1);
		}
		else {
			dfs(currentS + 1, currentT, depth + 1);
		}
	}
}

int main(void) {
	int C;
	cin >> C;

	for (int i = 0; i < C; i++) {
		int S, T;
		cin >> S >> T;
		result = 1 << 30;
		dfs(S, T, 0);
		if (result == 1 << 30)
			cout << "impossible\n";
		else
			cout << result << "\n";
	}
}
