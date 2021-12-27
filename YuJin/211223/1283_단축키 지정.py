import sys
input = sys.stdin.readline

n = int(input())
s = []
for _ in range(n): s.append(str(input().strip()))

alphabet = []
string = []

for v in s:
    split_s = v.split(' ')
    t, c, transform = '', 0, False
    for e in split_s:
        if not e.lower() in string and not e[0].lower() in alphabet and not transform:
            string.append(e.lower())
            alphabet.append(e[0].lower())
            transform = True
            if not len(t) == 0: t += ' ['+e[0]+']'+e[1:]
            else: t += '['+e[0]+']'+e[1:]
        else:
            c += 1
            if not len(t) == 0: t += ' ' + e
            else: t += e
    t2 = ''
    if c == len(split_s):
        for i in range(len(v)):
            if not v[i].lower() in alphabet and not v[i] == ' ':
                alphabet.append(v[i].lower())
                t2 += v[:i] + '[' + v[i] + ']' + v[i+1:]
                break
        if len(t2) == 0: t2 += ' '.join(split_s)
        print(t2)
    else: print(t)
