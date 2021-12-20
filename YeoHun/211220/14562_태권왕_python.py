import sys
from collections import deque
input = sys.stdin.readline

C = int(input())

def bfs(startS, startT):
    queue = deque()
    queue.append((startS, startT))
    visited = [False] * 600
    depth = 0
    while len(queue) != 0:
        size = len(queue)
        for _ in range(size):
            now = queue.popleft()

            s = now[0]
            t = now[1]

            amazingKickS = s*2
            amazingKickT = t+3
            normalKickS = s+1
            normalKickT = t

            if amazingKickS == amazingKickT or normalKickS == normalKickT:
                return depth + 1

            if not visited[s] and s < t:
                queue.append((amazingKickS, amazingKickT))
                queue.append((normalKickS, normalKickT))
        depth += 1
    return 0

for _ in range(C):
    S, T = map(int, input().split())
    print(bfs(S, T))
