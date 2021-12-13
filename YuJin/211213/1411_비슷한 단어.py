import itertools
import sys
input = sys.stdin.readline

n = int(input())
s = [input().strip() for i in range(n)]
count = 0

def compare(a,b):
    check1 = [-1] * 26
    check2 = [-1] * 26
    for i in range(len(a)):
        ord_a = ord(a[i])-97
        ord_b = ord(b[i])-97
        if check1[ord_a] == -1 and check2[ord_b] == -1: #둘 다 처음 변환될 때
            check1[ord_a] = ord_b
            check2[ord_b] = ord_a
        else:
            if check1[ord_a] != ord_b or check2[ord_b] != ord_a:
                return False
    return True

for element in list(itertools.combinations(s,2)):
    e0, e1 = element[0],element[1]
    if len(e0) != len(e1):
        continue
    if compare(e0,e1):
        count += 1

print(count)
