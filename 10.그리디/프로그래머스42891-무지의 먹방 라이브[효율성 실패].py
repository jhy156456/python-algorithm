def solution(food_times, k):
    second = 0
    index = 0

    def calculateNextIndex(localIndex):
        localIndex += 1
        localIndex %= len(food_times)
        count = 1
        while food_times[localIndex] == 0:
            localIndex += 1
            localIndex %= len(food_times)
            count += 1
            if count > len(food_times):
                return -1
        return localIndex

    while second != k:
        food_times[index] -= 1
        index = calculateNextIndex(index)
        if index == -1:
            return -1
        second += 1

    return index+1


print(solution([3, 1, 2], 5))
