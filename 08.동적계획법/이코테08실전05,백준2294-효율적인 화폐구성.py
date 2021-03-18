import sys
sys.setrecursionlimit(10**6)
def dp(value):
    if value < 1: return
    if values[value] != 0: return values[value]
    minResult = 1000000
    for i in range(n):
        prevResult = dp(value - list[i])
        if prevResult is not None:
            minResult = min(minResult, prevResult+1)
            # print("value - list[i]", value - list[i], "minResult : ", minResult, "prevResult", prevResult)
    # print("value : ",value,"minResult",minResult)
    values[value] = minResult
    return minResult


n, m = map(int, input().split())
values = [0] * 100001
list = []

for i in range(n):
    val = int(input())
    values[val] = 1
    list.append(val)

result = dp(m)
if result is not None and result != 1000000:
    print(result)
else :
    print("-1")