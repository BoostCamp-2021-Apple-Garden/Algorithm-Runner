#include <iostream>
using namespace std;

int n, m;
int d[200][200], e[200][200];

int main(void) {
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (i==j) d[i][j] = 0;
            else d[i][j] = 987654321;
        }
    }
    for (int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        d[a-1][b-1] = c;
        d[b-1][a-1] = c;
        e[a-1][b-1] = b-1;
        e[b-1][a-1] = a-1;
    }
    for (int k=0; k<n; k++) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (d[i][k]+d[k][j] < d[i][j]) {
                    d[i][j] = d[i][k]+d[k][j];
                    e[i][j] = e[i][k];
                }
            }
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (i==j) cout << "- ";
            else cout << e[i][j]+1 << " ";
        }
        cout << endl;
    }
    return 0;
}