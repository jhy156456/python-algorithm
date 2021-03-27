from collections import deque
import sys
input = sys.stdin.readline

n, m, k, x = map(int, input().split())
# 인접리스트 방식 선언
graph = [[] for i in range(n + 1)]
dist = [-1] * (n + 1)
for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)

result = []

queue = deque([x])
dist[x] = 0
while queue:
    curNode = queue.popleft()
    for i in graph[curNode]:
        nextNode = i
        if dist[nextNode] == -1:
            dist[nextNode] = dist[curNode] + 1
            if dist[nextNode] == k:
                result.append(nextNode)
            queue.append(nextNode)

result.sort()
if len(result) == 0:
    print(-1)
else:
    for i in result:
        print(i)
