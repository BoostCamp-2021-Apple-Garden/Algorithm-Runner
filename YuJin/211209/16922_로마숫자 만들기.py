import sys
import itertools
input = sys.stdin.readline

n = int(input())
result = set()
num = [1, 5, 10, 50]
p = itertools.combinations_with_replacement(num, n)
for v in p:
    result.add(sum(v))

print(len(result))
