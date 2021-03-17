def binarySearch(target, start, end):
    if start > end:
        return
    center = (start + end) // 2
    if target == nArr[center]:
        return center
    elif target < nArr[center]:
        return binarySearch(target, start, center - 1)
    else:
        return binarySearch(target, center + 1, end)

n = int(input())
nArr = list(map(int, input().split()))
m = int(input())
mArr = list(map(int, input().split()))

nArr = sorted(nArr)
for i in range(m):
    value = binarySearch(mArr[i], 0, m - 1)
    print(value)
    if not value or value is None:
        print("no")
    else:
        print("yes")
