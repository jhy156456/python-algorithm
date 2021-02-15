n = int(input())
k = list(map(str, input().split()))

i = 0
resultRow = 1
resultCol = 1
while i < len(k):
    if k[i] == 'R' and resultRow<n-1:
        resultRow += 1
    elif k[i] == 'L' and 1<resultRow:
        resultRow -= 1
    elif k[i] == 'U' and 1<resultCol:
        resultCol -= 1
    elif k[i] == 'D' and resultCol < n-1:
        resultCol += 1
    i +=1

print(resultCol,resultRow)
