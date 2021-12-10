#include <string>
#include <vector>
#include <iostream>
using namespace std;

int l[1000000], r[1000000];

int solution(vector<int> a) {
    int answer = 0;
    for (int i=0; i<a.size(); i++) {
        if (i==0) l[i]=a[i];
        else l[i]=min(a[i], l[i-1]);
    }
    for (int i=a.size()-1; i>=0; i--) {
        if (i==a.size()-1) r[i]=a[i];
        else r[i]=min(a[i], r[i+1]);
    }
    for (int i=0; i<a.size(); i++) {
        if (a[i]==l[i] || a[i]==r[i]) answer++;
    }
    return answer;
}