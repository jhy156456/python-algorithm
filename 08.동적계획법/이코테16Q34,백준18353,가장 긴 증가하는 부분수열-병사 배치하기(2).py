n = int(input())

array = list(map(int,input().split()))

d = [1] * n
for i in range(1,n):
    for j in range(i):
        if array[j] > array[i]:
            d[i] = max(d[i], d[j] + 1)
print(n - max(d))
