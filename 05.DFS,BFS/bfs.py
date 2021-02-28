from _collections import deque

n, m, v = map(int, input().split())
graph = [[] for _ in range(n + 1)]
for _ in range(m):
    key, child = map(int, input().split())
    graph[key].append(child)

queue = deque()
visited = [False] * 9


def bfs(node):
    print(node, end=' ')
    queue.popleft()
    for i in graph[node]:
        if (visited[i]):
            continue
        else:
            if not visited[i]:
                visited[i] = True
                queue.append(i)

    if (len(queue) > 0):
        bfs(queue[0])


queue.append(v)
visited[v] = True
bfs(1)
