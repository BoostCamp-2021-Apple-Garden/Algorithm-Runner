import sys

n = int(sys.stdin.readline().strip())
men_height = list(map(int, sys.stdin.readline().split()))
women_height = list(map(int, sys.stdin.readline().split()))
negative_men_height = sorted([n for n in men_height if n < 0], key=lambda x: abs(x))
positive_men_height = sorted([n for n in men_height if 0 < n], key=lambda x: abs(x))
negative_women_height = sorted([n for n in women_height if n < 0], key=lambda x: abs(x))
positive_women_height = sorted([n for n in women_height if 0 < n], key=lambda x: abs(x))
answer = 0

negative_man = 0
negative_woman = 0
positive_man = 0
positive_woman = 0

while positive_woman < len(positive_women_height) and negative_man < len(negative_men_height):
    if abs(positive_women_height[positive_woman]) < abs(negative_men_height[negative_man]):
        answer += 1
        positive_woman += 1
        negative_man += 1
    else:
        negative_man += 1

while negative_woman < len(negative_women_height) and positive_man < len(positive_men_height):
    if abs(negative_women_height[negative_woman]) > abs(positive_men_height[positive_man]):
        answer += 1
        negative_woman += 1
        positive_man += 1
    else:
        negative_woman += 1

print(answer)

