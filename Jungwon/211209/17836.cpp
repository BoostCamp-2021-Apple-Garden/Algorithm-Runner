#include <iostream>
#include <utility>
#include <cstdlib>
#include <queue>
using namespace std;

int n, m, t;
int a[100][100];

struct Point {
    int row;
    int col;
    int time;
};

Point gram;
Point princess;

int distance(Point a, Point b) {
    return abs(a.row-b.row) + abs(a.col-b.col);
}

int bfs(Point dest) {
    queue<Point> q;
    bool visited[100][100];
    int time = 0;
    int dir[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};

    for(int i=0; i<n; i++) {
        for (int j=0; j<m; j++) visited[i][j] = false;
    }
    visited[0][0] = true;

    Point start = {0, 0, 0};
    q.push(start);
    while(!q.empty()) {
        int r = q.front().row;
        int c = q.front().col;
        int time = q.front().time;
        q.pop();
        // cout << "row: " << r << ", col: " << c << ", time: " << time << endl;
        if (time > t) return -1;
        if (r==dest.row && c==dest.col) return time;

        for (int i=0; i<4; i++) {
            int newr = r + dir[i][0];
            int newc = c + dir[i][1];
            if (newr<0 || newr>=n || newc<0 || newc>=m) continue;
            if (a[newr][newc]==1 || visited[newr][newc]) continue;
            // cout << "newr: " << newr << ", newc: " << newc << endl;
            visited[newr][newc] = true;
            Point newp = {newr, newc, time+1};
            q.push(newp);
        }
    }
    return -1;
}

int main(void) {
    Point gram;
    cin >> n >> m >> t;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> a[i][j];
            if (a[i][j]==2) {
                gram.row = i;
                gram.col = j;
            }
        }
    }

    Point princess = {n-1, m-1, 0};
    int time1 = bfs(princess);
    int time2 = bfs(gram);
    if (time2>=0) time2 += distance(gram, princess);
    if (time2>t) time2 = -1;
    
    if (time1<0 && time2<0) {
        cout << "Fail" << endl;
    } else if (time1<0) {
        cout << time2 << endl;
    } else if (time2<0) {
        cout << time1 << endl;
    } else {
        cout << min(time1, time2) << endl;
    }
    return 0;
}