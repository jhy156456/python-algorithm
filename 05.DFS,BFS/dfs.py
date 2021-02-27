n, m, v = map(int, input().split())
graph = [[] for _ in range(n + 1)]
for _ in range(m):
    key, child = map(int, input().split())
    graph[key].append(child)

visited = [0 for i in range(n + 1)]
result = []
print(graph)
def dfs(v, node):
    result.append(node)
    visited[node] = True
    for i in graph[node]:
        if (visited[i]):
            continue
        else:
            dfs(v, i)

dfs(visited, 1)
print(result)