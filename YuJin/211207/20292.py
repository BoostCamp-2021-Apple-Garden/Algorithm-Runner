import sys
input = sys.stdin.readline

w, r = set(), set()
result = []

while True:
    v = str(input())
    s = v.split()
    if s[0] == 'WRITE':
        if s[1] in w or s[3] in r or s[3] in w:
            r.clear()
            w.clear()
            result.append('WAIT\n')
        w.add(s[3])
        r.add(s[1])
    elif s[0] == 'READ':
        if s[1] in w:
            r.clear()
            w.clear()
            result.append('WAIT\n')
        r.add(s[1])
    else:
        break
    result.append(v)

result.append('EXIT')
print("".join(result))
