#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> mp, mn, fp, fn;

int main(void) {
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        int height;
        cin >> height;
        if (height>0) mp.push_back(height);
        else mn.push_back(height);
    }
    for (int i=0; i<n; i++) {
        int height;
        cin >> height;
        if (height>0) fp.push_back(height);
        else fn.push_back(height);
    }
    sort(mp.begin(), mp.end(), greater<int>());
    sort(fp.begin(), fp.end(), greater<int>());
    sort(mn.begin(), mn.end());
    sort(fn.begin(), fn.end());
    int i=0, j=0, cnt=0;
    while (i<mp.size() && j<fn.size()) {
        int sum = mp[i] + fn[j];
        if (sum<0) {
            cnt++;
            j++;
        }
        i++;
    }
    i=0;
    j=0;
    while (i<mn.size() && j<fp.size()) {
        int sum = mn[i] + fp[j];
        if (sum<0) {
            cnt++;
            i++;
        }
        j++;
    }
    cout << cnt << endl;
    return 0;
}