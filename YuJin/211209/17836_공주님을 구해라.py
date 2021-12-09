import sys
from collections import deque
input = sys.stdin.readline

n, m, t = map(int,input().split())
g = []

for _ in range(n):
    g.append(list(map(int, input().split())))
visited = [[False] * m for _ in range(n)]

dx = [-1, 1, 0, 0]
dy = [0, 0, 1, -1]

def bfs():
    c = 0
    queue = deque()
    queue.append((0, 0))
    visited[0][0] = True
    while queue:
        x, y = queue.popleft()
        visited[x][y] = True
        if g[x][y] == 2:
            print("?")
            c = g[x][y] + abs(n - 1 - x) + abs(m - 1 - y)
            g[n - 1][m - 1] = c
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx < 0 or ny < 0 or nx >= n or ny >= m:
                continue
            if g[nx][ny] == 0 or g[nx][ny] == 2:
                if not visited[nx][ny]:
                    queue.append((nx, ny))
                    g[nx][ny] = g[x][y] + 1
    if g[n - 1][m - 1] == 0: return -1
    else: return min(c, g[n - 1][m - 1])

time = bfs()

if time == -1 or time > t: print("Fail")
else: print(time)
