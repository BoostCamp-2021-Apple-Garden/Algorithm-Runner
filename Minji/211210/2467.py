import sys

n = int(sys.stdin.readline().strip())
liquids = list(map(int, sys.stdin.readline().split()))

start = 0
end = len(liquids) - 1
a = liquids[start]
b = liquids[end]
min_diff = a + b

while start < end:
    if abs(liquids[start] + liquids[end]) < abs(min_diff):
        min_diff = liquids[start] + liquids[end]
        a = liquids[start]
        b = liquids[end]
    if 0 < liquids[start] + liquids[end]:
        end = end - 1
    else:
        start = start + 1

print(a, b)
