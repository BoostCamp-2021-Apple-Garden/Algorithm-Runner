import sys
input = sys.stdin.readline

n, m, s = int(input()), int(input()), str(input())
count = 0
i, p = 0, 0

while i < m-1:
    if s[i:i+3] == 'IOI':
        p += 1
        if p == n:
            count += 1
            p -= 1
        i +=1
    else:
        p = 0
    i += 1

print(count)
