import sys

input = sys.stdin.readline

n = int(input())

tArr = [0] * (n + 1)
pArr = [0] * (n + 1)
dp = [0] * (n + 1)

for i in range(1, n + 1):
    t, p = map(int, input().split())
    tArr[i] = t
    pArr[i] = p


def dynamic(day):
    if day+tArr[day] > n+1: return 0
    if day+tArr[day] == n+1: return pArr[day]
    if dp[day] != 0: return dp[day]
    curProfit = pArr[day]
    max = curProfit # p[i]
    # print("day : " , day)
    nextDay = day + tArr[day]
    for i in range(nextDay, n + 1):
        dp[day] = curProfit + dynamic(i) # max(p[i]+dp[t[i]+i]],max_value)1
        if dp[day] > max:
            max = dp[day]
            # print("i", i, end=' ')
            # print("max", max)

    # print(dp[day])
    return max


result = 0
for i in range(1, n + 1):
    value = dynamic(i)
    if value > result:
        # print(i)
        result = value

print(result,end='')
