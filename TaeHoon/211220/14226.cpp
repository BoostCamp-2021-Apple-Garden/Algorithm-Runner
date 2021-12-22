#include <iostream>
#include <queue>

using namespace std;

int targetCount;

bool visited[10000][10000] = {false, };

struct Node {
	public:
		int currentCount;
		int clipBoard;
		int depth;
		Node(int currentCount, int clipBoard, int depth) : currentCount(currentCount), clipBoard(clipBoard), depth(depth) {}
};

int bfs() {
	queue<Node> q;

	q.push(Node(1, 0, 0));
	visited[1][0] = true;
	while (!q.empty()) {
		Node element = q.front();
		q.pop();
		if (element.currentCount == targetCount) {
			return element.depth;
		}
		if (!visited[element.currentCount][element.currentCount]) {
			visited[element.currentCount][element.currentCount] = true;
			q.push(Node(element.currentCount, element.currentCount, element.depth + 1));
		}
		if (element.clipBoard > 0 && !visited[element.currentCount + element.clipBoard][element.clipBoard]) {
			visited[element.currentCount + element.clipBoard][element.clipBoard] = true;
			q.push(Node(element.currentCount + element.clipBoard, element.clipBoard, element.depth + 1));
		}
		if (element.currentCount > 0 && !visited[element.currentCount - 1][element.clipBoard]) {
			visited[element.currentCount - 1][element.clipBoard] = true;
			q.push(Node(element.currentCount - 1, element.clipBoard, element.depth + 1));
		}
	}
	return 0;
}

int main(void) {
	cin >> targetCount;
	cout << bfs() << endl;
}
