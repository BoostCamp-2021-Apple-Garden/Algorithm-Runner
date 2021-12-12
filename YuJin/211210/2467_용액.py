import sys
input = sys.stdin.readline

n = int(input())
s = list(map(int, input().split()))

start = 0
end = n-1
m = float('inf')
result = []

while True:
    if start >= end: break
    mix = abs(s[start] + s[end])
    if mix < m:
        m = mix
        result = [s[start],s[end]]
    elif s[start] + s[end] > 0:
        end -= 1
    else:
        start += 1

print(result[0],result[1])
