#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int R, C, N, dir[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
char a[200][200], b[200][200], c[200][200];
queue<pair<int, int> > q;

void f(char from[200][200], char to[200][200]) {
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            if (from[i][j]=='O') {
                q.push(make_pair(i, j));
                to[i][j]='.';
            } else to[i][j]='O';
        }
    }
    while(!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        for (int i=0; i<4; i++) {
            int newr = row + dir[i][0];
            int newc = col + dir[i][1];
            if (newr<0||newr>=R||newc<0||newc>=C) continue;
            to[newr][newc]='.';
        }
    }
}

int main(void) {
    cin >> R >> C >> N;
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) cin >> a[i][j];
    }
    if (N==1||N%2==0) {
        for (int i=0; i<R; i++) {
            for (int j=0; j<C; j++) {
                if (N==1) cout << a[i][j];
                else cout << 'O';
            }
            cout << endl;
        }
        return 0;
    }
    f(a, b);
    f(b, c);
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            if (N%4==1) cout << c[i][j];
            else cout << b[i][j];
        }
        cout << endl;
    }
    return 0;
}