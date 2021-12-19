#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int minTime = 10000000;
vector<int> eat_times;
vector<int> oven_times;

void dfs(int count, int max_time, int oven_time_sum, vector<bool> visited) {
	if (count == 0) {
		minTime = min(max_time, minTime);
	}
	for (int i = 0; i < N; i++) {
		if (visited[i] == false) {
			visited[i] = true;
			oven_time_sum += oven_times[i];
			max_time = max(max_time, oven_time_sum + eat_times[i]);
			dfs(count - 1, max_time, oven_time_sum, visited);
			oven_time_sum -= oven_times[i];
			visited[i] = false;
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int time;
		cin >> time;
		eat_times.push_back(time);
	}
	for (int i = 0; i < N; i++) {
		int time;
		cin >> time;
		oven_times.push_back(time);
	}

	vector<bool> visited;
	for (int i = 0; i < N; i++) {
		visited.push_back(false);
	}
	dfs(N, 0, 0, visited);

	cout << minTime << endl;

	return 0;
}
