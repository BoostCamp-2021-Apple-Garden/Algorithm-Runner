#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> v;
pair<int, int> p;
long long minValue = 2000000001;

int main(void) {
    cin >> n;
    for (int i=0; i<n; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    int left=0,  right=n-1;
    while(left<right) {
        int leftNum = v[left];
        int rightNum = v[right];
        long long sum = (long long)leftNum + (long long)rightNum;
        if (abs(sum) < minValue) {
            minValue = abs(sum);
            p = make_pair(leftNum, rightNum);
        }
        if (sum<0) left++;
        else right--;
    }
    cout << p.first << " " << p.second << endl;
    return 0;
}