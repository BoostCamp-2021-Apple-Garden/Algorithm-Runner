import sys
input = sys.stdin.readline

r, c, n = map(int,input().split())
grid = []
dx = [-1,1,0,0]
dy = [0,0,-1,1]

def transform(grid):
    temp = []
    for _ in range(r):
        temp.append(["O"] * c)
    for i in range(r):
        for j in range(c):
            if grid[i][j] != "O": continue
            temp[i][j] = "."
            for next in range(4):
                nx, ny = i + dx[next], j + dy[next]
                if nx < 0 or nx >= r: continue
                if ny < 0 or ny >= c: continue
                temp[nx][ny] = "."
    return temp

if n % 2 == 0:
    for _ in range(r):
        s = "O" * c
        print(s)
else:
    for _ in range(r):
        grid.append(list(str(input()).strip()))
    if n == 1:
        for i in range(r):
            print(''.join(grid[i]))
    else:
        i = 0
        while i < n+2:
            grid = transform(grid)
            i += 2

        for i in range(r):
            print(''.join(grid[i]))
