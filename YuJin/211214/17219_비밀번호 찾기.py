import sys
input = sys.stdin.readline

n, m = map(int, input().split())
d = {}
for _ in range(n):
    url, pw = map(str, input().split())
    d[url] = pw

for _ in range(m):
    print(d[str(input().strip())])
