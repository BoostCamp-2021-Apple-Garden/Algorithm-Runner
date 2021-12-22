#include <iostream>
#include <queue>

using namespace std;
bool road[1000][1000] = {false, };
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
int X, Y, N;

struct Node {
	public:
		int y, x, depth;
		Node(int y, int x, int depth) : y(y), x(x), depth(depth) {}
};

bool is_in_range(int y, int x) {
	return y >= 0 && y < 1000 && x >= 0 && x < 1000;
}

int bfs() {
	queue<Node> q;
	q.push(Node(500, 500, 0));
	road[0][0] = true;
	while (!q.empty()) {
		Node element = q.front();
		q.pop();
		if (element.y == Y && element.x == X) {
			return element.depth;
		}
		for (int i = 0; i < 4; i++) {
			int newY = dy[i] + element.y;
			int newX = dx[i] + element.x;
			if (is_in_range(newY, newX) && !road[newY][newX]) {
				road[newY][newX] = true;
				q.push(Node(newY, newX, element.depth + 1));
			}
		}
	}
	return 0;
}

int main(void) {
	cin >> Y >> X >> N;
	X += 500;
	Y += 500;
	for (int i = 0; i < N; i++) {
		int y, x;
		cin >> y >> x;
		y += 500;
		x += 500;
		road[y][x] = true;
	}
	cout << bfs() << endl;
}
