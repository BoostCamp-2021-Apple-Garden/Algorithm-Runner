#include <iostream>
using namespace std;

string s;

int check(int start, int end, int cnt) {
    if (start > end) return cnt;
    if (s[start]==s[end]) return check(start+1, end-1, cnt);
    if (cnt==1) return 2;
    int result1 = check(start+1, end, cnt+1);
    int result2 = check(start, end-1, cnt+1);
    return min(result1, result2);
}

int main(void) {
    int T;
    cin >> T;
    for (int t=0; t<T; t++) {
        cin >> s;
        int start = 0, end = s.size()-1;
        int result = check(start, end, 0);
        cout << result << endl;
    }
    return 0;
}