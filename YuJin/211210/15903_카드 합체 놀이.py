import sys
import heapq
input = sys.stdin.readline

n, m = map(int, input().split())
card = list(map(int,input().split()))
heap = []

for v in card:
    heapq.heappush(heap, v)

# 두번째 방법 -> 훨씬 빠름
for _ in range(m):
    first, second = heapq.heappop(heap), heapq.heappop(heap)
    s = first + second
    heapq.heappush(heap, s)
    heapq.heappush(heap, s)

print(sum(heap))

# 처음 했던 방법
# for _ in range(m):
#     card.sort()
#     s = card[0] + card[1]
#     card[0],card[1] = s, s
#
# print(sum(card))
