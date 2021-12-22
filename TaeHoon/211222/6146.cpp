#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int road[1000][1000] = {0, };
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
int X, Y, N;

struct Node {
	public:
		int y, x, depth;
		vector<pair<int, int> > v;
		Node(int y, int x, int depth, vector<pair<int, int> > v) : y(y), x(x), depth(depth), v(v) { }
};

bool is_in_range(int y, int x) {
	return y >= 0 && y < 1000 && x >= 0 && x < 1000;
}

void display(int road[1000][1000]) {
	cout << "\n";
	for (int i = 495; i < 508; i++) {
		for (int j = 498; j < 508; j++) {
			road[i][j] == 1 ? cout << "M " : road[i][j] == 2 ? cout << "* " : road[i][j] == 3 ? cout << "^ " :  cout << ". ";
		}
		cout << "\n";
	}
}

int bfs() {
	queue<Node> q;
	vector<pair<int, int> > v;
	v.push_back(make_pair(500, 500));
	q.push(Node(500, 500, 0, v));
	road[0][0] = 2;
	int display_road[1000][1000];
	for (int i = 0; i < 1000; i++)
		for (int j = 0; j < 1000; j++)
			display_road[i][j] = road[i][j];

	while (!q.empty()) {
		Node element = q.front();
		q.pop();
		if (element.y == Y && element.x == X) {
			for (int i = 0; i < element.v.size(); i++) {
				display_road[element.v[i].first][element.v[i].second] = 2;
				display(display_road);
			}
			return element.depth;
		}
		for (int i = 0; i < 4; i++) {
			int newY = dy[i] + element.y;
			int newX = dx[i] + element.x;
			if (is_in_range(newY, newX) && (!road[newY][newX] || road[newY][newX] == 3)) {
				road[newY][newX] = 2;
				element.v.push_back(make_pair(newY, newX));
				q.push(Node(newY, newX, element.depth + 1, element.v));
				element.v.pop_back();
			}
		}
	}
	return 0;
}

int main(void) {
	cin >> Y >> X >> N;
	X += 500;
	Y += 500;
	road[Y][X] = 3;
	for (int i = 0; i < N; i++) {
		int y, x;
		cin >> y >> x;
		y += 500;
		x += 500;
		road[y][x] = 1;
	}
	cout << bfs() << endl;
}
