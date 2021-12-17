from collections import deque

n, m = map(int, input().split())
map = [list(map(int, input().split())) for i in range(n)]
answer = 0
maxLen = 0

def bfs(startRow, startCol):
    queue = deque()
    queue.append((startRow, startCol, 0))
    global answer, maxLen
    visited = [[False] * m for i in range(n)]
    rowDir = [0, 0, 1, -1]
    colDir = [1, -1, 0, 0]
    while len(queue) != 0:
        now = queue.popleft()
        nowRow = now[0]
        nowCol = now[1]
        nowDist = now[2]
        
        if nowDist > maxLen:
            answer = map[nowRow][nowCol] + map[startRow][startCol]
            maxLen = nowDist
        elif nowDist == maxLen:
            answer = max(answer, map[nowRow][nowCol] + map[startRow][startCol])

        for (nextRowMove, nextColMove) in zip(rowDir, colDir):
            nextRow = nowRow + nextRowMove
            nextCol = nowCol + nextColMove

            if 0 <= nextRow < n and 0 <= nextCol < m \
                    and not visited[nextRow][nextCol]\
                    and map[nextRow][nextCol] != 0:
                visited[nowRow][nowCol] = True
                queue.append((nextRow, nextCol, nowDist + 1))

checked = set()
for (rowIndex, row) in enumerate(map):
    for (colIndex, col) in enumerate(row):
        if col != 0 and (rowIndex, colIndex) not in checked:
            checked.add((colIndex, rowIndex))
            bfs(rowIndex, colIndex)
print(answer)