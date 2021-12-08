#include <iostream>
#include <map>
#include <vector>
using namespace std;

int N, cnt=0;
map<string, int> m;
vector<int> v;

int main(void) {
    cin >> N;
    for (int i=0; i<N; i++) {
        string str;
        cin >> str;
        m[str] = i;
    }
    for (int i=0; i<N; i++) {
        string str;
        cin >> str;
        v.push_back(m[str]);
    }
    for (int i=0; i<v.size(); i++) {
        for (int j=i+1; j<v.size(); j++) {
            if (v[i]>v[j]) {
                cnt++;
                break;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}