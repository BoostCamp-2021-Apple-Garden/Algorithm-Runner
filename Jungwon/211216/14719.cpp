#include <iostream>
using namespace std;

int main(void) {
    int h, w, a[500], b[500], c[500], answer=0;
    cin >> h >> w;
    for (int i=0; i<w; i++) {
        cin >> a[i];
        if (i==0 || a[i]>b[i-1]) b[i]=a[i];
        else b[i]=b[i-1];
    }
    for (int i=w-1; i>=0; i--) {
        if (i==w-1|| a[i]>c[i+1]) c[i]=a[i];
        else c[i]=c[i+1];
        answer += min(b[i], c[i]) - a[i];
    }
    cout << answer << endl;
    return 0;
}