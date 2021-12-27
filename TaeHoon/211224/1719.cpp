#include <iostream>
#include <queue>
#define INF 100000000

using namespace std;

int n, m;
int arr[201][201] = {INF, };

struct Node {
	int index, weight;
	Node(int index, int weight) : index(index), weight(weight) {};
};

struct cmp {
	bool operator()(Node &a, Node &b) {
		return a.weight < b.weight;
	}
};

void solution(int start) {
	priority_queue<Node, vector<Node>, cmp> pq;
	int trace[201] = {0, };

	pq.push(Node(start, 0));
	arr[start][start] = 0;
	for (int i = 0; i < n; i++) {
		if (arr[start][i] != INF) {
			pq.push(Node(i, arr[start][i]));
			trace[i] = start;
		}
	}
	while (!pq.empty()) {
		Node element = pq.top();
		pq.pop();
		for (int i = 0; i < n; i++) {
			if (arr[start][i] > element.weight + arr[element.index][i]) {
				arr[start][i] = element.weight + arr[element.index][i];
				trace[i] = element.index;
				pq.push(Node(i, arr[start][i]));
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (i == start)
			cout << "- ";
		else if (trace[i] == start)
			cout << i + 1<< " ";
		else {
			int index = i;
			while (1) {
				if (trace[index] == start) {
					cout << index + 1 << " ";
					break;
				}
				else
					index = trace[index];
			}
		}
	}
		cout << "\n";
}

int main(void) {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = INF;
		}
	}
	for (int i = 0; i < m; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		arr[a - 1][b - 1] = w;
		arr[b - 1][a - 1] = w;
	}
	for (int i = 0; i < n; i++) {
		solution(i);
	}
}
