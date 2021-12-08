import sys
input = sys.stdin.readline

result = ""
i = 1

while True:
    l, p, v = map(int, input().split())
    if l == 0 and p == 0 and v == 0 : break
    n_value = (v % p)
    if n_value > l:
        result += "Case " + str(i) + ": " + str(l * (v // p) + l) + "\n"
    else:
        result += "Case " + str(i) + ": " + str(l*(v//p)+n_value) + "\n"
    i += 1

print(result)
