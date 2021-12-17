#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int n, answer = (1<<30);
    cin >> n;
    vector<int> a(n), b(n), idx(n);
    for (int i=0; i<n; i++) idx[i] = i;
    for (int i=0; i<n; i++) cin >> b[i];
    for (int i=0; i<n; i++) cin >> a[i];
    do {
        int start=0;
        int lunchTime = 0;
        for (int i=0; i<n; i++) {
            start += a[idx[i]];
            int total = start + b[idx[i]];
            lunchTime = max(lunchTime, total);
        }
        answer = min(answer, lunchTime);
    } while(next_permutation(idx.begin(), idx.end()));
    cout << answer << endl;
    return 0;
}