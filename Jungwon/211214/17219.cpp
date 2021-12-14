#include <iostream>
#include <map>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, m;
    map<string, string> mymap;
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        string website, password;
        cin >> website >> password;
        mymap[website] = password;
    }
    for (int i=0; i<m; i++) {
        string website;
        cin >> website;
        cout << mymap[website] << "\n";
    }
    return 0;
}