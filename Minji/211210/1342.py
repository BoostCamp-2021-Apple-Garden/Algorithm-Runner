import sys
from itertools import permutations

s = list(sys.stdin.readline().strip())
answer = 0
char_cnt = set(s)


def factorial(n):
    result = 1
    for i in range(1, n + 1):
        result *= i
    return result


if len(char_cnt) == len(s):
    print(factorial(len(s)))
else:
    candidates = set(permutations(s))

    for candidate in candidates:
        isValid = True
        for i in range(1, len(candidate)):
            if candidate[i - 1] == candidate[i]:
                isValid = False
                break
        if isValid: answer += 1

    print(answer)
