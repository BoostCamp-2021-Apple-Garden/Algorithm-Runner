#include <iostream>
#include <vector>

using namespace std;

int N, M;
int arr[50][50];
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
vector<pair<int, int> > v; // routeLength, sum

bool is_in_range(int y, int x) {
	return y >= 0 && y < N && x >= 0 && x < M && arr[y][x] > 0;
}
	// cout << "start : " << start.first << ", " << start.second << endl;
	// cout << "end : " << y << ", " << x << endl;
	// cout << "sum : " << arr[start.first][start.second] + arr[y][x] << endl;
	// cout << "arr[start.first][start.second] : " << arr[start.first][start.second] << endl;
	// cout << "arr[y][x] : " << arr[y][x] << endl;
	// cout << "length : " << routeLength << endl;
void bfs(int y, int x, int routeLength, int start, int check[50][50]) {
	v.push_back(make_pair(routeLength, arr[y][x] + start));

	for (int i = 0; i < 4; i++) {
		int newY = y + dy[i];
		int newX = x + dx[i];
		if (is_in_range(newY, newX) && check[newY][newX] == false) {
			check[newY][newX] = true;
			bfs(newY, newX, routeLength + 1, start, check);
			check[newY][newX] = false;
		}
	}
}

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) {
		return a.second > b.second;
	}
	else {
		return a.first < b.first;
	}
}

int main(void) {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int check[50][50] = {0, };
			if (arr[i][j] > 0) {
				check[i][j] = true;
				bfs(i, j, 0, arr[i][j], check);
			}
		}
	}

	sort(v.begin(), v.end(), cmp);
	// while (!pq.empty()) {
	// 	cout << pq.top().first << ", " << pq.top().second << endl;
	// 	pq.pop();
	// }

	cout << v[0].second << endl;
}
