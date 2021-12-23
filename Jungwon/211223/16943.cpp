#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    string a, b, c = "-1";
    cin >> a >> b;
    sort(a.begin(), a.end());
    do {
        if (a.front()=='0') continue;
        if (stoi(a) > stoi(b)) break;
        c = a;
    } while(next_permutation(a.begin(), a.end()));
    cout << c << endl;
    return 0;
}