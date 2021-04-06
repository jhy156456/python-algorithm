import heapq
import sys

input = sys.stdin.readline
n, k = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(n)]
s, x, y = map(int, input().split())
curSecondq = []
nextSecondq = []
# 푸쉬 하려면 계속 이렇게 해야함
for i in range(n):
    for j in range(n):
        if graph[i][j] != 0:
            heapq.heappush(nextSecondq, (graph[i][j], (i, j)))
# 상,하,좌,우
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
second = 0
while second < s:
    curSecondq = nextSecondq
    nextSecondq =[]
    while curSecondq:
        cur = heapq.heappop(curSecondq)
        curVirus = cur[0]
        curX, curY = cur[1]
        for i in range(4):
            nextX, nextY = curX + dx[i], curY + dy[i]
            if nextX < 0 or nextX >= n or nextY < 0 or nextY >= n:
                continue
            if graph[nextX][nextY]!=0 : continue
            heapq.heappush(nextSecondq, (curVirus, (nextX, nextY)))
            graph[nextX][nextY] = curVirus
    second += 1

if graph[x-1][y-1] == 0:
    print(0)
else: print(graph[x-1][y-1])
