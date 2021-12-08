import sys
input = sys.stdin.readline

t, n = map(int, input().split())
v = []
for _ in range(n):
    v.append(list(map(int, input().split())))

v.sort(key=lambda x: (-x[2], x[0]))
for _ in range(t):
    if v == []: break

    if v[1][2] > v[0][2]:
        v[0], v[1] = v[1], v[0]
    elif v[1][2] == v[0][2]:
        if v[0][0] > v[1][0]:
            v[0], v[1] = v[1], v[0]

    print(v[0][0])
    v[0][1] -= 1
    v[0][2] -= 1

    if v[0][1] == 0: v.pop(0)
