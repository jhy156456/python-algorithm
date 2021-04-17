n = int(input())
graph = [list(map(int, input())) for _ in range(n)]


def compress(row, col, size):
    # 전부0,1인지 검사한다
    zeroCount = 0
    oneCount = 0
    if size == 1: return str(graph[row][col])
    for i in range(row, row + size):
        for j in range(col, col + size):
            if graph[i][j] == 0:
                zeroCount += 1
            elif graph[i][j] == 1:
                oneCount += 1
    if zeroCount == size * size:
        return '0'
    elif oneCount == size * size:
        return '1'
    else:
        half = size // 2
        return '(' + compress(row, col, half) + \
               compress(row, col + half, half) + \
               compress(row + half, col, half) + \
               compress(row + half, col + half, half) + ')'


if n == 1:
    print(graph[0][0])
else:
    zeroCount = 0
    oneCount = 0
    for i in range(0, n):
        for j in range(0, n):
            if graph[i][j] == 0:
                zeroCount += 1
            elif graph[i][j] == 1:
                oneCount += 1
    if zeroCount == n * n:
        print('0')
    elif oneCount == n * n:
        print('1')
    else:
        print('(' + compress(0, 0, n // 2) +
          compress(0, n // 2, n // 2) +
          compress(n // 2, 0, n // 2) +
          compress(n // 2, n // 2, n // 2) + ')')
