#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

struct Process {
    int id;
    int time;
    int priority;
};

struct cmp {
    bool operator()(Process a, Process b) {
        if (a.priority == b.priority) {
            return a.id > b.id;
        }
        return a.priority < b.priority;
    }
};

int T, n;
priority_queue<Process, vector<Process>, cmp> pq;

int main(void) {
    scanf("%d %d", &T, &n);
    for (int i=0; i<n; i++) {
        int A, B, C;
        scanf("%d %d %d", &A, &B, &C);
        Process p;
        p.id = A;
        p.time = B;
        p.priority = C;
        pq.push(p);
    }
    for (int i=1; i<=T; i++) {
        if (pq.empty()) break;
        Process p = pq.top();
        pq.pop();
        printf("%d\n", p.id);
        p.priority--;
        p.time--;
        if (p.time > 0) pq.push(p);
    }
    return 0;
}