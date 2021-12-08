#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

set<string> s;

int main(void) {
    int N;
    cin >> N;
    for (int i=0; i<N; i++) {
        string str;
        cin >> str;
        s.insert(str);
        reverse(str.begin(), str.end());
        if (s.find(str) != s.end()) {
            int size = str.size();
            cout << size << " " << str[size/2] << endl; 
        }
    }
}