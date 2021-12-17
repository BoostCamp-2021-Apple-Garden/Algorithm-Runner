#include <iostream>
using namespace std;

int n;
string s = "";

bool isGood(string str) {
    int size = str.size();
    for (int i=1; size-2*i>=0; i++) {
        if (str.substr(size-2*i, i) == str.substr(size-i, i)) return false;
    }
    return true;
}

void dfs(int depth) {
    if (depth==n) return;
    depth++;
    for (char c='1'; c<='3'; c++) {
        if(isGood(s+c)) {
            s += c;
            dfs(depth);
            if (s.size()==n) return;
            else s.pop_back();
        }
    }
}

int main(void) {
    cin >> n;
    dfs(0);
    cout << s << endl;
    return 0;
}