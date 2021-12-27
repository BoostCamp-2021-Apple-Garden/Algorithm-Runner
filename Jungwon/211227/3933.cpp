#include <iostream>
using namespace std;

int arr[33000];

int main(void) {
    for (int a=0; a<182; a++) {
        for (int b=a; b<182; b++) {
            for (int c=b; c<182; c++) {
                for (int d=c; d<182; d++) {
                    int num = a*a + b*b + c*c + d*d;
                    if (num >= (1<<15)) break;
                    arr[num]++;
                }
            }
        }
    }
    while(true) {
        int n;
        cin >> n;
        if (n==0) break;
        cout << arr[n] << endl;
    }
    return 0;
}