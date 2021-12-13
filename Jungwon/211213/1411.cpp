#include <iostream>
#include <map>
using namespace std;

int main(void) {
    int n, answer=0;
    map<string, int> m;
    cin >> n;
    for (int i=0; i<n; i++) {
        string str, newStr = "";
        map<char, char> temp;
        char alphabet = 'a';
        cin >> str;
        for (int i=0; i<str.size(); i++) {
            char c = str[i];
            if (temp.find(c) == temp.end()) {
                temp[c] = alphabet;
                alphabet++;
            }
            newStr += temp[c];
        }
        if (m.find(newStr) == m.end()) m[newStr] = 1;
        else m[newStr]++;
    }
    for (auto it=m.begin(); it!=m.end(); it++) {
        int cnt = it->second;
        answer += cnt * (cnt-1) / 2;
    }
    cout << answer << endl;
    return 0;
}