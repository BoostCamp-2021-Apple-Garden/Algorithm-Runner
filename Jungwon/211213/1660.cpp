#include <iostream>
#include <deque>
using namespace std;

deque<int> dq;
int a[300001];

int main(void) {
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        int k = dq.size() + 1;
        if (i == k*(k+1)*(k+2)/6) {
            dq.push_front(i);
            a[i]=1;
        } else {
            int minValue = 0;
            for (int j=0; j<dq.size(); j++) {
                int temp = 1 + a[i-dq[j]];
                if (minValue == 0 || temp < minValue) minValue = temp;
            }
            a[i] = minValue;
        }
    }
    cout << a[n] << endl;
    return 0;
}