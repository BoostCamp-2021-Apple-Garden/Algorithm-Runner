#include <iostream>
#include <queue>
using namespace std;

int main(void) {
    queue<string> q1, q2;
    string str, tmp="";
    bool flag = true;
    cin >> str;
    for (int i=0; i<str.size(); i++) {
        if (str[i]==':') {
            if (tmp!="") {
                while(tmp.size()<4) tmp = '0' + tmp;
                if (flag) q1.push(tmp);
                else q2.push(tmp);
                tmp = "";
            } else if (i>0) {
                flag = false;
            }
        } else {
            tmp += str[i];
        }
    }
    while(tmp.size()<4) tmp = '0' + tmp;
    if (flag) q1.push(tmp);
    else q2.push(tmp);
    int n = 8 - q1.size() - q2.size();
    flag = false;
    while (!q1.empty()) {
        if (flag) cout << ":";
        else flag = true;
        cout << q1.front();
        q1.pop();
    }
    for (int i=0; i<n; i++) {
        if (flag) cout << ":";
        else flag = true;
        cout << "0000";
    }
    while (!q2.empty()) {
        if (flag) cout << ":";
        else flag = true;
        cout << q2.front();
        q2.pop();
    }
    cout << endl;
    return 0;
}