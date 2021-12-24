#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, answer=987654321;
int w[10][10];
vector<int> v;

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i=0; i<n; i++) {
        v.push_back(i);
        for (int j=0; j<n; j++) {
            cin >> w[i][j];
        }
    }
    do {
        int sum = 0;
        bool success = true;
        for (int i=0; i<n-1; i++) {
            int from = v[i];
            int to = v[i+1];
            if (w[from][to]==0) {
                success = false;
                break;
            }
            sum += w[from][to];
        }
        if (!success) continue;
        int from = v[n-1];
        int to = v[0];
        if (w[from][to]==0) continue;
        sum += w[from][to]; 
        if (sum<answer) answer = sum;
    } while (next_permutation(v.begin(), v.end()));
    cout << answer << endl;
    return 0;
}