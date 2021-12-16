#include <iostream>
#include <queue>
using namespace std;

int main(void) {
    int n, a[20];
    priority_queue<int, vector<int>, greater<int> > pq;

    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<(1<<n); i++) {
        int sum = 0;
        for (int j=0; j<n; j++) {
            if (i&(1<<j)) sum += a[j];
        }
        pq.push(sum);
    }
    int answer;
    do {
        answer = pq.top();
        pq.pop();
    } while (!pq.empty() && pq.top() - answer <= 1);
    answer++;
    cout << answer << endl;
    return 0;
}