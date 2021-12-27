#include <iostream>
#include <strings.h>

using namespace std;

int N;
int cost[11][11];
int result = 1 << 30;
int visited[11] = {false, };

void dfs(int start, int depth, int currentIndex, int currentCost) {
	if (depth == 1 && cost[currentIndex][start] != 0) {
		result = min(result, currentCost + cost[currentIndex][start]);
		return ;
	}
	for (int i = 0 ; i < N; i++) {
		if (!visited[i] && cost[currentIndex][i]) {
			visited[i] = true;
			dfs(start, depth - 1, i, currentCost + cost[currentIndex][i]);
			visited[i] = false;
		}
	}
}

int main(void) {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> cost[i][j];
		}
	}

	for (int i = 0 ; i < N; i++) {
		bzero(visited, 11);
		visited[i] = true;
		dfs(i, N, i, 0);
	}

	cout << result << endl;

}
