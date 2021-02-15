n,k = map(int , input().split())
result = 0
while n !=1:
    if n%k != 0:
        n = n-1
    else:
        n = n/k
    result = result + 1

print(result)