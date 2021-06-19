n = int(input())
# n = map(int,input().split())
n = 1000-n 
coin_types = [500, 100, 50, 10, 5, 1]
count = 0
for coin in coin_types:
    count += n // coin
    n = n % coin

print(count)
