from collections import deque
import sys
input = sys.stdin.readline

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

n, l, r = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(n)]
visited = [[0] * n for _ in range(n)]
isUnionGo = True

def bfs(i, j):
    queue = deque([(i, j)])
    visited[i][j] = True
    union = []
    union.append((i, j))
    unionPopulation = graph[i][j]
    unionCount = 1

    while queue:
        curX, curY = queue.pop()
        for i in range(4):
            nextX = curX + dx[i]
            nextY = curY + dy[i]
            if 0 <= nextX < n and 0 <= nextY < n:
                if visited[nextX][nextY] == 0 and l <= abs(graph[nextX][nextY] - graph[curX][curY]) <= r:
                    queue.append((nextX, nextY))
                    visited[nextX][nextY] = True
                    union.append((nextX, nextY))
                    unionPopulation += graph[nextX][nextY]
                    unionCount += 1

    if unionCount >1:
        #인구이동을 할 나라가 있으면
        for i in range(len(union)):
            curX, curY = union[i]
            graph[curX][curY] = unionPopulation // unionCount
        return True
    else:
        return False


isUnionMove = False
isMoveCount = 0
while True:
    for i in range(n):
        for j in range(n):
            if visited[i][j] == 0:
                # 방문 하지 않았다면 연합체크
                # 하나라도 참이면 인구이동을 한것이고 다음 이동을 조사해야한다
                # 전부다 거짓이면 인구이동이 없는것이고 종료한다
                isUnionMove = bfs(i, j) or isUnionMove

    for i in range(n):
        for j in range(n):
            visited[i][j] = 0
    if isUnionMove:
        isMoveCount +=1
        isUnionMove = False
    else :
        break
print(isMoveCount)