import sys
input = sys.stdin.readline
from functools import reduce

s = str(input().strip())

def multiply(arr):
    return reduce(lambda x, y: x * y, arr)

d = {'H': 1, 'C': 12, 'O': 16}
l = []

for i in range(len(s)):
    if s[i] == '(':
        l.append(s[i])
    elif s[i] == 'H' or s[i] == 'C' or s[i] == 'O':
        l.append(d[s[i]])
    elif s[i] == ')':
        temp = 0
        while True:
            v = l.pop()
            if v == '(': break
            else:
                temp += v
        l.append(temp)
    else:
        l.append(l.pop() * int(s[i]))
print(sum(l))
