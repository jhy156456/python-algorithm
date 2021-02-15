n, m, k = map(int, input().split())
data = list(map(int, input().split()))

data.sort(reverse=True)

print(data)
i = 0
result = 0
originalK = k
if data[0] != data[1]:
    while i != m:
        if k > 0:
            result = result + data[0]
        else: 
            result = result + data[1]
            k = originalK
        k = k - 1
        i = i + 1
else:
    result = data[0] * m

print(result)
