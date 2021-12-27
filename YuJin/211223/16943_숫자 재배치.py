import sys
import itertools
input = sys.stdin.readline

a, b = map(str, input().split())

def solution(a, b):
    for v in sorted(list(itertools.permutations(list(a), len(a))), reverse=True):
        s = ''.join(v)
        if int(s) <= int(b) and s[0] != '0': return s
    return -1

print(solution(a, b))
