n, m = map(int, input().split())
x, y, d = map(int, input().split())

a = [list(map(int, input().split())) for _ in range(n)]
flag = [[0 for _ in range(n)] for _ in range(m)]
flag[x][y] = True
# left, right, up, down
dx = [0, 0, -1, 1]  # 행이동, y좌표이동
dy = [-1, 1, 0, 0]  # 열이동, x좌표이동

dict = dict()
dict[0] = (-1, 0)
dict[1] = (0, -1)
dict[2] = (1, 0)
dict[3] = (0, 1)
isBreak = 0
result = 0
while True:
    isBreak += 1
    d += 1 # 방향전환
    d = d % 4
    nextX = x + dict[d][0] # 바라 보고 있는 방향으로 이동
    nextY = y + dict[d][1]
    print("current : ", x, y)  ## (1,0) 다음 (2,1)이 나와야함
    print("next : ",nextX, nextY) ## (1,0) 다음 (2,1)이 나와야함
    if flag[nextX][nextY] == 0 and a[nextX][nextY] != 1:  # 이동한 방향에 가보지 않은 칸이 존재하거나 바다가 아니라면
        flag[nextX][nextY] = True
        x = nextX
        y = nextY
        isBreak = 1
        result += 1

    if isBreak == 4:  # 네 방향 모두 가본 칸
        # 한칸 뒤로이동
        backDirection = (d + 2) % 4
        x += dict[backDirection][0]
        y += dict[backDirection][1]
        if a[x][y] == 1:  # 뒤가 바다라면
            break


print(result+1)