import sys
input = sys.stdin.readline

n = input()
eat = list(map(int, input().split()))
heat = list(map(int, input().split()))
time = sum(heat) + min(eat)

for i in range(len(eat)):
	time = max(time, heat[i] + eat[i])
	
print(time)
