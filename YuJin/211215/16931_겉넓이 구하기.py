import sys
input = sys.stdin.readline

n, m = map(int,input().split())
cube, width = [], 0

for _ in range(n):
    t = list(map(int,input().split()))
    cube.append(t)
    width += len(t)

width *= 2 #윗면과 바닥 넓이

for i in range(n): #바깥면 넓이 더하기
    width += cube[i][0] #모서리 한번더 더하기
    width += cube[i][m - 1]
    if i == 0 or i == n-1:
        if i == 0 and i == n-1:
            width += sum(cube[i]) * 2
        else:
            width += sum(cube[i])

di = [-1, 1, 0, 0]
dj = [0, 0, 1, -1]

for i in range(n): #높이 차이로 인한 넓이 구하기
    for j in range(m):
        for next in range(4):
            ni = i + di[next]
            nj = j + dj[next]
            if ni < 0 or ni >= n: continue
            if nj < 0 or nj >= m: continue
            if cube[i][j] > cube[ni][nj]:
                width += cube[i][j] - cube[ni][nj]
print(width)
