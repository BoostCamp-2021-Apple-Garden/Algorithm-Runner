#include <iostream>

using namespace std;

string A;
int B;
int result = -1;

void dfs(int depth, int visited[11], string current) {
	if (depth == 0) {
		if (stoi(current) < B)
			result = max(result, stoi(current));
		return ;
	}
	for (int i = 0; i < A.size(); i++) {
		if (!visited[i]) {
			if (current == "" && A[i] == '0')
				continue;
			visited[i] = true;
			dfs(depth - 1, visited, current + A[i]);
			visited[i] = false;
		}
	}
}

int main(void) {
	cin >> A >> B;

	int visited[11] = {false, };
	dfs(A.size(), visited, "");
	cout << result << endl;
}
