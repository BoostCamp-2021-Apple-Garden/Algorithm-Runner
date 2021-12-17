#include <iostream>
#include <queue>

using namespace std;

int N, M;
int arr[50][50];
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
int maxLength = 0;
int maxSum = 0;

class Point {
	public:
		int y, x;
		int routeLength;

		Point(int y, int x, int routeLength) : y(y), x(x), routeLength(routeLength) {}
};

queue<Point> q; // 좌표, 거리

bool is_in_range(int y, int x) {
	return y >= 0 && y < N && x >= 0 && x < M && arr[y][x] > 0;
}

void bfs(int y, int x) {

	int check[50][50] = {false, };
	q.push(Point(y, x, 0));
	check[y][x] = true;
	while (!q.empty()) {
		Point point = q.front();
		if (point.routeLength == maxLength) {
			maxSum = max(arr[y][x] + arr[point.y][point.x], maxSum);
		}
		else if (point.routeLength > maxLength) {
			maxLength = point.routeLength;
			maxSum = arr[y][x] + arr[point.y][point.x];
		}
		for (int i = 0; i < 4; i++) {
			int newY = dy[i] + point.y;
			int newX = dx[i] + point.x;
			if (is_in_range(newY, newX) && check[newY][newX] == false) {
				check[newY][newX] = true;
				q.push(Point(newY, newX, point.routeLength + 1));
			}
		}
		q.pop();
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
			if (arr[i][j] > 0) {
				bfs(i, j);
			}
		}
	}
	cout << maxSum << endl;
}
