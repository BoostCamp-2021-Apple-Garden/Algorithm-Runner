#include <iostream>
#include <queue>
using namespace std;

int main(void) {
    int n, m;
    priority_queue<long long, vector<long long>, greater<long long> > pq;
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        long long num;
        cin >> num;
        pq.push(num);
    }
    for (int i=0; i<m; i++) {
        long long a = pq.top();
        pq.pop();
        long long b = pq.top();
        pq.pop();
        pq.push(a+b);
        pq.push(a+b);
    }
    long long sum=0;
    while(!pq.empty()) {
        sum += pq.top();
        pq.pop();
    }
    cout << sum << endl;
    return 0;
}