#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    string str;
    int cnt=0;

    cin >> str;
    sort(str.begin(), str.end());
    do {
        bool isLucky = true;
        for (int i=0; i<str.size()-1; i++) {
            if (str[i] == str[i+1]) {
                isLucky = false;
                break;
            }
        }
        if (isLucky) cnt++;
    } while(next_permutation(str.begin(), str.end()));
    cout << cnt << endl;
    return 0;
}