import sys
import heapq

heap = []
n, m = map(int, sys.stdin.readline().split())
cards = list(map(int, sys.stdin.readline().split()))

for card in cards:
    heapq.heappush(heap, card)

for i in range(m):
    new_value = heapq.heappop(heap) + heapq.heappop(heap)
    heapq.heappush(heap, new_value)
    heapq.heappush(heap, new_value)

print(sum(heap))
