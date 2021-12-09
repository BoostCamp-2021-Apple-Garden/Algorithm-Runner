import sys
from itertools import permutations

numbers = []
number_set = set()

n = int(sys.stdin.readline())
k = int(sys.stdin.readline())

for i in range(0, n):
    numbers.append(int(sys.stdin.readline()))

candidate_list = list(permutations(numbers, k))

for elem in candidate_list:
    string = ""
    for num in list(elem):
        string += str(num)
    number_set.add(string)

print(len(list(number_set)))
