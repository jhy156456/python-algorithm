from collections import deque

n = int(input())
k = int(input())

# 상, 우, 하, 좌
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

matrix = [[0] * n for _ in range(n)]
# apple = 1
# snake = 2
for i in range(k):
    appleX, appleY = map(int, input().split())
    matrix[appleX-1][appleY-1] = 1
matrix[0][0] = 2

l = int(input())
snakes = deque()

for i in range(l):
    snakes.append(input().split())
snakeTotalLocation = deque([(0, 0)])
curSnakeHeadX = 0
curSnakeHeadY = 0
curSnakeHeadDirection = 1
# snake[0] = 현재 뱀의머리 행,열
# snake[1] = 현재 뱀의 방향 0,1,2,3
# snake[2] = 뱀의 길이
second = 0
while True:
    second += 1
    nextSnakeHeadX = curSnakeHeadX + dx[curSnakeHeadDirection]
    nextSnakeHeadY = curSnakeHeadY + dy[curSnakeHeadDirection]
    curSnakeHeadX = nextSnakeHeadX
    curSnakeHeadY = nextSnakeHeadY

    if (nextSnakeHeadX < 0 or nextSnakeHeadX >= n or
            nextSnakeHeadY < 0 or nextSnakeHeadY >= n or
            matrix[nextSnakeHeadX][nextSnakeHeadY] == 2):
        # 다음 좌표가 벽이거나 자기 자신이라면
        break

    if matrix[nextSnakeHeadX][nextSnakeHeadY] == 1:
        snakeTotalLocation.append((nextSnakeHeadX, nextSnakeHeadY))
        matrix[nextSnakeHeadX][nextSnakeHeadY] = 2
    elif matrix[nextSnakeHeadX][nextSnakeHeadY] == 0:
        snakeTotalLocation.append((nextSnakeHeadX, nextSnakeHeadY))
        matrix[nextSnakeHeadX][nextSnakeHeadY] = 2
        # 다음 좌표가 아무것도 아니라면 기존 뱀 좌표를 지우고 그냥 이동한다
        tailX, tailY = snakeTotalLocation.popleft()
        matrix[tailX][tailY] = 0

    if len(snakes) >0:
        changeSecond, changeDirection = snakes.popleft()

        if second == int(changeSecond):
            # 방향 이동 해야할 시간이면
            if changeDirection == 'D':
                # 오른쪽으로 90도 이동
                curSnakeHeadDirection += 1
            elif changeDirection == 'L':
                # 왼쪽으로 90도 이동
                curSnakeHeadDirection -= 1
            curSnakeHeadDirection %= 4
        else:
            # 방향 이동 시간이 아니면 왼쪽에 다시 넣는다
            snakes.appendleft((changeSecond, changeDirection))


print(second)
