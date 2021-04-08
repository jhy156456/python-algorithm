n, c = list(map(int, input().split(' ')))
array = []
for _ in range(n):
    a = int(input())
    array.append(a)

array.sort()

start = 1
end = array[-1]
result = 0
while start <= end:
    mid = (start + end) // 2
    value = array[0]
    count = 1
    for i in range(1, n):
        if array[i] >= value + mid:
            value = array[i]
            count += 1

    if count < c:
        # 공유기 설치 횟수가 적다면 갭을 줄여야한다
        end = mid - 1
    else:
        # 공유기 설치 횟수가 많거나 같다면
        # 현재 gap을 저장하고 gap을 키워서 키운 gap도 공유기 설치가 가능한지
        # 확인해야한다
        result = mid
        start = mid + 1

print(result)
