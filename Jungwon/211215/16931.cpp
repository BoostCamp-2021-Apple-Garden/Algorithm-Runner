#include <iostream>
using namespace std;

int main(void) {
    int n, m, a[100][100], dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}, answer=0;
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) cin >> a[i][j];
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            int sum = 2;
            for (int k=0; k<4; k++) {
                int newi = i + dir[k][0];
                int newj = j + dir[k][1];
                if (newi<0||newi>=n||newj<0||newj>=m) sum += a[i][j];
                else if (a[i][j]>a[newi][newj]) sum += (a[i][j]-a[newi][newj]);
            }
            answer += sum;
        }
    }
    cout << answer << endl;
    return 0;
}