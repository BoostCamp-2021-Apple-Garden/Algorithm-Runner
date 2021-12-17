#include <iostream>
#include <utility>
#include <queue>
#include <vector>
using namespace std;

struct Node {
    pair<int, int> point;
    int count;
};

int N, M, a[50][50];
pair<int, int> maxValue = make_pair(0, 0);
vector<pair<int, int> > v;
queue<Node> q;
bool visited[50][50];

bool shouldUpdate(pair<int, int> maxValue, pair<int, int> newValue) {
    if (newValue.first > maxValue.first) return true;
    if (newValue.first == maxValue.first && newValue.second > maxValue.second) return true;
    return false;
}

pair<int, int> bfs(pair<int, int> start) {
    int dir[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) visited[i][j] = false;
    }
    pair<int, int> result = make_pair(0, 0);
    visited[start.first][start.second] = true;
    q.push((Node){start, 0});
    while(!q.empty()) {
        int row = q.front().point.first;
        int col = q.front().point.second;
        int count = q.front().count;
        q.pop();
        pair<int, int> tmp = make_pair(count, a[start.first][start.second]+a[row][col]);
        if (shouldUpdate(result, tmp)) result = tmp;
        for (int i=0; i<4; i++) {
            int newr = row + dir[i][0];
            int newc = col + dir[i][1];
            if (newr<0||newr>=N||newc<0||newc>=M) continue;
            if (a[newr][newc]==0||visited[newr][newc]) continue;
            visited[newr][newc] = true;
            q.push((Node){make_pair(newr, newc), count+1});
        }
    }
    return result;
}

int main(void) {
    cin >> N >> M;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> a[i][j];
            if (a[i][j]>0) v.push_back(make_pair(i, j));
        }
    }
    for (int i=0; i<v.size(); i++) {
        pair<int, int> result = bfs(v[i]);
        if (shouldUpdate(maxValue, result)) maxValue = result;
    }
    cout << maxValue.second << endl;
    return 0;
}