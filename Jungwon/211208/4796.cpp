#include <iostream>
using namespace std;

int main(void) {
    int L, P, V;
    for (int i=1; ; i++) {
        cin >> L >> P >> V;
        if (L + P + V == 0) break;
        int answer = V / P * L + min(V % P, L);
        cout << "Case " << i << ": " << answer << endl;
    }
    return 0;
}