#include <iostream>
#include <set>
using namespace std;

int n, k, arr[10];
set<string> s;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

string toString(int x) {
    string result = "";
    if (x>=10) result += '0' + x/10;
    result += '0' + x%10;
    return result;
}

void permutation(int idx) {
    if (idx==k) {
        string str = "";
        for (int i=0; i<k; i++) {
            str += toString(arr[i]);
        }
        s.insert(str);
        return;
    }
    for (int i=idx; i<n; i++) {
        swap(arr[idx], arr[i]);
        permutation(idx+1);
        swap(arr[idx], arr[i]);
    }
}

int main(void) {
    cin >> n >> k;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    permutation(0);
    cout << s.size() << endl;
    return 0;
}