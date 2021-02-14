n = int(input())
result = 0

for i in range(n + 1):
    for j in range(60):
        for k in range(60):
            if '3'in str(i) + str(j) + str(k):
                result += 1


print(result)

"""
시간 = 24
분 = 00~59
초 = 00~59
"""
