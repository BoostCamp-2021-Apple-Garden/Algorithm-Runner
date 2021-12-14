import sys

n = int(sys.stdin.readline())
dices = []
max_dice_sum = 0
top_num = 0
counter = {0: 5, 1: 3, 2: 4, 3: 1, 4: 2, 5: 0}
for i in range(n):
    dices.append(list(map(int, sys.stdin.readline().split())))

for i in range(6):
    dice_sum = 0
    top_num = dices[0][i]
    for dice in dices:
        idx = dice.index(top_num)
        dice_sum += max(list(set(dice) - set([top_num, dice[counter[idx]]])))
        top_num = dice[counter[idx]]
    max_dice_sum = max(dice_sum, max_dice_sum)

print(max_dice_sum)

