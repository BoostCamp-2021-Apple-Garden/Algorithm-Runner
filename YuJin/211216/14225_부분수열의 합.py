import sys
import itertools
input = sys.stdin.readline

n = int(input())
num = list(map(int,input().split()))
num.sort()

c = 0
for i in range(len(num)):
    if c+1 < num[i]: break
    c += num[i]
print(c+1)

# 1번째 -> 느림
# result = num.copy() 
# a = 0
#
# for i in range(2,len(num)+1):
#     for v in list(itertools.combinations(num,i)):
#         result.append(sum(v))
#
# result.sort()
# result_max = result[-1]
# c = [i for i in range(1,result_max+2)]
# print(sorted(list(set(c)-set(result)))[0])
