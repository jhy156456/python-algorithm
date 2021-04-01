def binary_search(target, start, end):
    center = (start + end) // 2
    if start > end: return center
    sum = getSumList(center)
    # print("start",start,"end",end,"center",center,"sum",sum)
    if sum < target:
        return binary_search(target, start, center - 1)
    elif sum > target:

        return binary_search(target, center + 1, end)
    # 일치하는경우
    else:
        return center


def getSumList(minusValue):
    sum =0
    for i in list:
        if i > minusValue:
            sum += i - minusValue
    return sum


# def getSumList(minusValue):
#     sum = 0
#     for i in list:
#         sumValue = i-minusValue
#         if sumValue > 0:
#             sum = sum+ sumValue
#     return sum

n, m = map(int, input().split())
list = list(map(int, input().split()))
end = max(list)
result = print(binary_search(m, 0, end))

if result != None:
    print(result + 1)




