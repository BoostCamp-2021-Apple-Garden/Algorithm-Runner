#include <iostream>
using namespace std;
int P, Q, A, N, cnt=0;

void f(int a, int b, int c, int product, int k) {
    for (int i=c; (long long)(product)*i<=(long long)A; i++) {
        if (a*i==b) cnt++;
        else if (a*i>b) {
            if (k==N) return;
            f(a*i-b, b*i, i, product*i, k+1);
        }
    }
}

int main(void) {
    cin >> P >> Q >> A >> N;
    f(P, Q, 1, 1, 1);
    cout << cnt << endl;
}