import sys
from collections import deque
input = sys.stdin.readline

n, m, t = map(int,input().split())
g = []
s = []

for _ in range(n):
    g.append(list(map(int, input().split())))

visited = [[0] * m for _ in range(n)]

dx = [-1, 1, 0, 0]
dy = [0, 0, 1, -1]

def bfs():
    c = float('inf')
    queue = deque()
    queue.append((0, 0))
    visited[0][0] = 1
    while queue:
        x, y = queue.popleft()
        if g[x][y] == 2:
            c = visited[x][y] - 1 + abs(n - 1 - x) + abs(m - 1 - y)
        if x == n-1 and y == m-1:
            return min(visited[x][y] - 1, c)
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx < 0 or ny < 0 or nx >= n or ny >= m:
                continue
            if g[nx][ny] != 1:
                if not visited[nx][ny]:
                    queue.append((nx, ny))
                    visited[nx][ny] = visited[x][y] + 1
    return c

time = bfs()

if time > t: print("Fail")
else: print(time)
