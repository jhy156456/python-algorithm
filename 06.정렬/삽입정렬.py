numbers = list([7, 5, 9, 0, 3, 1, 6, 2, 4, 8])
results = []
results.append(numbers[0])

for i in range(1, len(numbers)):
    for j in range(i):
        if numbers[i] < results[j]:
            results.insert(j,numbers[i])
            break
        if j == i -1:
            results.append(numbers[i])

print(results)


