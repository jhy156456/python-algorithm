import sys

input = sys.stdin.readline
n, m = map(int, input().split())
INF = int(1e9)
# 2차원 리스트(그래프 표현)을 만들고, 모든 값을 무한으로 초기화
graph = [[INF] * (n + 1) for _ in range(n + 1)]

for a in range(1, n + 1):
    for b in range(1, n + 1):
        if a == b:
            graph[a][b] = 0
for _ in range(m):
    a, b = map(int, input().split())
    # a번 노드에서 b번 노드로 가는 비용이 1이라는 의미
    graph[a][b] = 1

# 플로이드 - 워셜
for k in range(1, n + 1):
    for a in range(1, n + 1):
        for b in range(1, n + 1):
            graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b])

count = 0
for a in range(1, n + 1):
    isComparable = True
    for b in range(1, n + 1):
        if a == b:
            continue
        if graph[a][b] != INF or graph[b][a] != INF:
            continue
        else:
            # print("graph[a][b] : ", graph[a][b], "graph[b][a] : ", graph[b][a])
            # print("a : ",a,"b : " ,b)
            isComparable = False
            break

    if isComparable == True:
        count += 1

print(count)
