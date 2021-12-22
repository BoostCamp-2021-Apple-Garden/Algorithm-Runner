#include <iostream>
#include <queue>

using namespace std;

int targetCount;
int result = 1 << 30;
bool visited[10000] = {false, };
bool visited2[10000] = {false, };
bool visited3[10000] = {false, };

struct Point {
	int count, depth, clipboard;
	Point(int count, int depth, int clipboard) : count(count), depth(depth), clipboard(clipboard) {}
};

bool is_in_range(int value) {
	return value >= 0 && value < 10000;
}

void bfs(int start) {
	queue<Point> q; // currentCount, depth

	q.push(Point(start, 0, 0));
	while (!q.empty()) {
		Point element = q.front();
		// cout << element.count << ", " << element.depth << ", " << element.clipboard << endl;
		q.pop();
		if (element.count == targetCount) {
			result = min(result, element.depth);
		}
		for (int i = 0; i < 3; i++) {
			int newCount;
			int newClipboard;
			if (i == 0) {
				newCount = element.count;
				newClipboard = element.count;
				if (is_in_range(newClipboard) && !visited2[newClipboard]) {
					visited2[newClipboard] = true;
					q.push(Point(newCount, element.depth + 1, newClipboard));
				}
			}
			else if (i == 1) {
				if (element.clipboard == 0)
					continue;
					// cout << "twice added result : " << element.count << ", " << element.clipboard << endl;
				newCount = element.count + element.clipboard;
				newClipboard = element.clipboard;
				if (is_in_range(newCount) && !visited[newCount]) {
					visited[newCount] = true;
					q.push(Point(newCount, element.depth + 1, newClipboard));
				}
			}
			else {
				newCount = element.count - 1;
				newClipboard = element.clipboard;
				if (is_in_range(newCount) && !visited3[newCount]) {
					visited3[newCount] = true;
					q.push(Point(newCount, element.depth + 1, newClipboard));
				}
			}
		}
	}
}

int main(void) {
	cin >> targetCount;

	bfs(1);
	cout << result;
}
