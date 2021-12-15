import sys
input = sys.stdin.readline

dice_num = int(input())
dices = []
pair = {0:5, 1:3, 2:4, 3:1, 4:2, 5:0}
for _ in range(dice_num):
    dices.append(list(map(int, input().split())))
max_n = 0

for i in range(6):
    n = 0
    start = i
    for j in range(dice_num):
        n += max(list(set(dices[j]) - set([dices[j][start], dices[j][pair[start]]])))
        if j != dice_num-1:
            start = dices[j+1].index(dices[j][pair[start]])
    max_n = max(max_n,n)
print(max_n)
