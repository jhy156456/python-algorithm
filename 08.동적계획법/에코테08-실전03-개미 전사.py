n = int(input())
list = list(map(int, input().split()))
dpList = [0] * len(list)


def dp(i):
    if i <= 1:
        return list[i]
    if dpList[i] != 0:
        return dpList[i]

    dpList[i] = max(dp(i - 1), dp(i - 2) + list[i])
    return dpList[i]

print(dp(n-1))
