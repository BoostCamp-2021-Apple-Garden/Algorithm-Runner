#include <iostream>
#include <vector>
#include <set>
using namespace std;

int n;
bool a[23];
set<int> s;

void combination(int idx, int r) {
    if (idx==n+3&&r!=0) return;
    if (r==0) {
        vector<int> v;
        for (int i=0; i<n+3; i++) {
            if (a[i]) {
                v.push_back(i);
            }
        }
        int cntI = v[0];
        int cntV = v[1]-v[0]-1;
        int cntX = v[2]-v[1]-1;
        int cntL = n+2-v[2];
        int num = cntI + 5*cntV + 10*cntX + 50*cntL;
        s.insert(num);
        return;
    }

    a[idx] = true;
    combination(idx+1, r-1);
    a[idx] = false;
    combination(idx+1, r);
}

int main(void) {
    cin >> n;
    combination(0, 3);
    cout << s.size() << endl;
    return 0;
}