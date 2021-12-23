#include <iostream>
#include <stack>
using namespace std;

string str;
stack<int> s;

int main(void) {
    cin >> str;
    for (int i=0; i<str.size(); i++) {
        char c = str[i];
        if (c == '(') s.push(0);
        else if (c== ')') {
            int sum = 0;
            while (s.top()>0) {
                sum += s.top();
                s.pop();
            }
            s.pop();
            s.push(sum);
        }
        else if (c >= '2' && c <= '9') {
            int n = c - '0';
            int product = s.top() * n;
            s.pop();
            s.push(product);
        }
        else if (c=='H') s.push(1);
        else if (c=='C') s.push(12);
        else if (c=='O') s.push(16);
    }
    int answer = 0;
    while (!s.empty()) {
        answer += s.top();
        s.pop();
    }
    cout << answer << endl;
    return 0;
}