#include <iostream>
#include <vector>
using namespace std;

int a[100];
int nonDivisibleSubset(int k, vector<int> s) {
    int answer = 0;
    for (int i=0; i<s.size(); i++) {
        int r = s[i]%k;
        a[r]++;
    }
    for (int i=0; i<=k/2; i++) {
        if (i==0) answer += min(a[i], 1);
        else if (2*i==k) answer += min(a[i], 1);
        else answer += max(a[i], a[k-i]);
    }
    return answer;
}