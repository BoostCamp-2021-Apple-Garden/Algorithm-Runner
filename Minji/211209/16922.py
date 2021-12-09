import sys
from itertools import combinations_with_replacement

rome_numbers = [1, 5, 10, 50]
numbers_set = set()

n = int(sys.stdin.readline())

for elem in list(combinations_with_replacement(rome_numbers, n)):
    numbers_set.add(sum(list(elem)))

print(len(list(numbers_set)))
