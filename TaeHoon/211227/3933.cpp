#include <iostream>
#include <math.h>

using namespace std;

int dfs(int before, int sum, int target, int depth) {
	int result = 0;
	if (depth == 0 || sum == target) {
		if (sum == target)
			return 1;
		return 0;
	}
	for (int i = before; i <= sqrt(target); i++) {
		if (sum + i * i > target)
			continue;
		result += dfs(i, sum + i * i, target, depth - 1);
	}
	return result;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	while (1) {
		int n;
		cin >> n;
		if (n == 0)
			break;
		cout << dfs(1, 0, n, 4) << endl;
	}
}
