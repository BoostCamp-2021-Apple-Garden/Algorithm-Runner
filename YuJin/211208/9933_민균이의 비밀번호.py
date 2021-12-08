import sys
input = sys.stdin.readline

s = []
result = ""

for _ in range(int(input())+1):
    v = str(input()).strip()
    r_v = "".join(reversed(v))
    if v == r_v:
        result = v
        break
    if r_v in s:
        result = v
        break
    else: s.append(v)

l = list(result)
c = len(l)
print(c,l[c//2])

