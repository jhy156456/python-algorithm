def binarySearch(start, end):
    if start>end:
        return
    center = (start + end) // 2
    if k < array[center]:
        return binarySearch(start, center-1)
    elif k > array[center]:
        return binarySearch(center+1,end)
    else:
        return center

n, k = map(int, input().split())
array = list(map(int, input().split()))
print(binarySearch(0, n))
