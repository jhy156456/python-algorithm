from collections import deque
from itertools import combinations
import sys

input = sys.stdin.readline
n = int(input())
graph = [list(input().split()) for _ in range(n)]
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
tArray = []
voidSpace = []
for i in range(n):
    for j in range(n):
        if graph[i][j] == 'T':
            tArray.append((i, j))
        elif graph[i][j] == 'X':
            voidSpace.append((i, j))

permutationList = list(combinations(voidSpace, 3))


def isVisible():
    isStudentvisible = False
    for j in range(len(tArray)):
        curX, curY = tArray[j]
        for i in range(1, n):
            nextUpX = curX - i
            if 0 <= nextUpX < n:
                if graph[nextUpX][curY] == 'S':
                    # 학생을 만나면 이 장애물 케이스는 더이상 검사할 필요 없이 통과
                    return True
                elif graph[nextUpX][curY] == 'O':
                    # 벽이면 다음으로 넘어갈 필요 없이 학생이 보이지 않는다.
                    isStudentvisible = False
                    break
        for i in range(1, n):
            nextDownX = curX + i
            if 0 <= nextDownX < n:
                if graph[nextDownX][curY] == 'S':
                    return True
                elif graph[nextDownX][curY] == 'O':
                    isStudentvisible = False
                    break
        for i in range(1, n):
            nextRightY = curY + i
            if 0 <= nextRightY < n:
                if graph[curX][nextRightY] == 'S':
                    return True
                elif graph[curX][nextRightY] == 'O':
                    isStudentvisible = False
                    break
        for i in range(1, n):
            nextLeftY = curY - i
            if 0 <= nextLeftY < n:
                if graph[curX][nextLeftY] == 'S':
                    return True
                elif graph[curX][nextLeftY] == 'O':
                    isStudentvisible = False
                    break

    return isStudentvisible


isSVisible = True
for i in range(len(permutationList)):
    firtX = permutationList[i][0][0]
    firstY = permutationList[i][0][1]
    secondX = permutationList[i][1][0]
    secondY = permutationList[i][1][1]
    thirdX = permutationList[i][2][0]
    thirdY = permutationList[i][2][1]
    graph[firtX][firstY] = 'O'
    graph[secondX][secondY] = 'O'
    graph[thirdX][thirdY] = 'O'
    if isVisible():
        isSVisible = True
    else:
        # 학생이 보이지 않으면 통과
        isSVisible = False
        break
    graph[firtX][firstY] = 'X'
    graph[secondX][secondY] = 'X'
    graph[thirdX][thirdY] = 'X'

if isSVisible:
    # 학생을 볼 수 있다면
    print("NO")
else:
    # 학생을 볼수 없다면
    print("YES")
