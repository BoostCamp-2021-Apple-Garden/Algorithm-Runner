import sys
from collections import deque
input = sys.stdin.readline

d_y, d_x, n = map(int,input().split())
d_x += 500
d_y += 500
w = []
g = [[0] * 1001 for _ in range(1001)]
visited = [[False] * 1001 for _ in range(1001)]

for _ in range(n):
    b, a = map(int, input().split())
    a += 500
    b += 500
    visited[b][a] = True

dx = [-1, 1, 0, 0]
dy = [0, 0, 1, -1]

def bfs():
    q = deque()
    q.append((500, 500, 0))
    visited[500][500] = True
    while q:
        y, x, d = q.popleft()
        if x == d_x and y == d_y:
            return d
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx < 0 or ny < 0 or nx >= 1000 or ny >= 1000:
                continue
            if not visited[ny][nx]:
                q.append((ny, nx, d+1))
                visited[ny][nx] = True

print(bfs())
