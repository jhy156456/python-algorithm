n, m = map(int, input().split())

# a = [[int(x) for x in input().split()]for y in range(m)]
a = [list(map(int, input().split())) for _ in range(n)]
minResult = 0
for i in range(n):
    minResult = max(min(a[i]),minResult)

print(minResult)

"""문제풀이
- 로직 : 각 행에서 가장 작은값을 고른다, 다음 행에서 가장 작은 값을 고른다, 둘중에 큰값을 선택한다,
다음 행에 선택된 값으로 로직을 반복한다.
"""

