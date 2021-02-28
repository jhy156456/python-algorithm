from _collections import deque

n, m = map(int, input().split())
graph = []
for i in range(n):
    graph.append(list(map(int, input())))
dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]


def bfs(x, y):
    queue = deque([(0, 0)])
    while queue:
        curX, curY = queue.popleft()
        for i in range(4):
            nextX = curX + dx[i]
            nextY = curY + dy[i]
            if nextX > -1 and nextY > -1 and nextX < n and nextY < m:
                if graph[nextX][nextY] == 1:
                    print(nextX, nextY)
                    queue.append((nextX, nextY))
                    graph[nextX][nextY] = graph[curX][curY] + 1


bfs(0, 0)
print(graph[n - 1][m - 1])
