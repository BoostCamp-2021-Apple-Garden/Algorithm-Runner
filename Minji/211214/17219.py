import sys

n, m = list(map(int, sys.stdin.readline().split()))
password_dict = dict()
for i in range(n):
    url, password = sys.stdin.readline().split()
    password_dict[url] = password

for i in range(m):
    url = sys.stdin.readline().strip()
    print(password_dict[url])

