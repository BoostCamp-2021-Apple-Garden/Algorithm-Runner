from collections import deque

r, c, n = map(int, input().split())
map = [list(input()) for row in range(r)]

def updateTime():
    for (rowIndex, row) in enumerate(map):
        for (colIndex, col) in enumerate(row):
            if map[rowIndex][colIndex] >= 0:
                map[rowIndex][colIndex] += 1
def putBomb():
    for (rowIndex, row) in enumerate(map):
        for (colIndex, col) in enumerate(row):
            if map[rowIndex][colIndex] == -1:
                map[rowIndex][colIndex] = 0
def triggerBomb():
    rowDir = [0, 0, 1, -1]
    colDir = [-1, 1, 0, 0]
    for (rowIndex, row) in enumerate(map):
        for (colIndex, col) in enumerate(row):
            for (nextRowMove, nextColMove) in zip(rowDir, colDir):
                nextRow = rowIndex + nextRowMove
                nextCol = colIndex + nextColMove
                if 0 <= nextRow < r \
                        and 0 <= nextCol < c \
                        and map[rowIndex][colIndex] == 3 \
                        and map[nextRow][nextCol] != 3:
                    map[nextRow][nextCol] = -1
            if map[rowIndex][colIndex] == 3:
                map[rowIndex][colIndex] = -1


for (rowIndex, row) in enumerate(map):
    for (colIndex, col) in enumerate(row):
        if col == "O":
            map[rowIndex][colIndex] = 0
        else:
            map[rowIndex][colIndex] = -1


for i in range(1, n+1):
    updateTime()
    if i == 1:
        continue
    if i % 2 == 0:
        putBomb()
    else:
        triggerBomb()

for row in map:
    for col in row:
        print("." if col == -1 else "O", end="")
    print()