import sys
input = sys.stdin.readline
import itertools

n = int(input())
road = [list(map(int, input().split())) for _ in range(n)]
time = float('inf')
for v in itertools.permutations(i for i in range(n)):
    temp = 0
    for i in range(n-1):
        f = False
        if road[v[i]][v[i+1]] != 0:
            temp += road[v[i]][v[i+1]]
        else:
            f = True
            break
    if f: continue
    if road[v[-1]][v[0]] != 0:
        temp += road[v[-1]][v[0]]
    else:
        continue
    time = min(time,temp)

print(time)
