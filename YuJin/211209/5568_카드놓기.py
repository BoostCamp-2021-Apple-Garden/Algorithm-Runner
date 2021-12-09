import sys
import itertools
input = sys.stdin.readline

n = int(input())
k = int(input())
num = [input().strip() for i in range(n)]
result = set()
p = itertools.permutations(num, k)
for v in p:
    result.add(''.join(v))
print(len(result))
