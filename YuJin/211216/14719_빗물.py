import sys
input = sys.stdin.readline

h, w = map(int, input().split())
block = list(map(int, input().split()))
sum = 0

for i in range(1,w-1):
    #왼쪽에서 최대
    left_max = max(block[:i])
    # 오른쪽에서 최대
    right_max = max(block[i:])
    t = min(left_max, right_max) - block[i]
    if t > 0: sum += t

print(sum)
