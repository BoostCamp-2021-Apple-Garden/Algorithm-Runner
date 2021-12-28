import sys
import heapq
input = sys.stdin.readline
INF = int(1e9)

def find(start):
    q = []
    heapq.heappush(q,(0,start))
    distance = [INF] * (n+1)
    distance[start] = 0
    while q:
        dist, now = heapq.heappop(q)
        for v in g[now]:
            cost = dist + v[1]
            if cost < distance[v[0]]:
                distance[v[0]] = cost
                heapq.heappush(q, (cost, v[0]))
                result[v[0]][start] = now

n, m = map(int, input().split())
g = [[] for _ in range(n+1)]
result = [[0] * (n+1) for _ in range(n+1)]
for _ in range(m):
    a, b, c = map(int, input().split())
    g[a].append((b,c))
    g[b].append((a,c))

for i in range(1, n+1):
    find(i)

for i in range(1, n+1):
    for j in range(1,n+1):
        if i == j: print('-', end= ' ')
        else: print(result[i][j], end=' ')
    print()
