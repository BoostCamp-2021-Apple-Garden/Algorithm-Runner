#include <iostream>
#include <set>
using namespace std;

int alternate(string s) {
    int answer = 0;
    set<char> myset;
    for (int i=0; i<s.size(); i++) myset.insert(s[i]);
    
    for (auto i=myset.begin(); i!=myset.end(); i++) {
        for (auto j=myset.begin(); j!=myset.end(); j++) {
            if (*i == *j) continue;
            char c = *i;
            int cnt = 0;
            bool flag = true;
            for (int k=0; k<s.size(); k++) {
                if (s[k]==c) {
                    cnt++;
                    c = *i + *j - c;
                } else if (s[k]==(*i + *j -c)) {
                    flag = false;
                    break;
                }
            }
            if (flag==false) continue;
            if (cnt>answer) answer = cnt;
        }
    }
    return answer;
}