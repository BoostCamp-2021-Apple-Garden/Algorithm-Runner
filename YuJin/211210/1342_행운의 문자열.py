import sys
input = sys.stdin.readline

s = str(input().strip())
s_count = len(s)
cnt = 0
arr = [0] * 26

def permutatation(before, count):
    global cnt
    if count == s_count: cnt += 1
    else:
        for i in range(26):
            if arr[i] < 1 or i == before: continue
            arr[i] -= 1
            permutatation(i, count + 1)
            arr[i] += 1

for element in s:
    arr[ord(element) - 97] += 1

permutatation(-1,0)
print(cnt)
