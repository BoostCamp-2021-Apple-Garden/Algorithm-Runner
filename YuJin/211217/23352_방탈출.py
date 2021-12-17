import sys
from collections import deque
input = sys.stdin.readline

n, m = map(int, input().split())
g = []
before_max_len, max_len = 0, 0
max_num = 0

for _ in range(n):
    g.append(list(map(int, input().split())))

dx = [-1, 1, 0, 0]
dy = [0, 0, 1, -1]

def bfs(start_x, start_y):
    global max_num, max_len, before_max_len
    visited = [[0] * m for _ in range(n)]
    q = deque()
    q.append((start_x, start_y))
    visited[start_x][start_y] = 1
    end_x, end_y = start_x,start_y
    while q:
        x, y = q.popleft()
        if g[x][y] == 0: continue
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx < 0 or ny < 0 or nx >= n or ny >= m:
                continue
            if g[nx][ny] != 0:
                if not visited[nx][ny]:
                    q.append((nx, ny))
                    visited[nx][ny] = visited[x][y] + 1
                    end_x, end_y = nx, ny
    if visited[end_x][end_y] >= max_len:
        max_len = visited[end_x][end_y]
        if max_len > before_max_len:
            max_num = g[start_x][start_y]+g[end_x][end_y]
        else:
            max_num = max(max_num,g[start_x][start_y]+g[end_x][end_y])
        before_max_len = visited[end_x][end_y]

for i in range(n):
    for j in range(m):
        if not g[i][j] == 0:
            bfs(i,j)

print(max_num)
