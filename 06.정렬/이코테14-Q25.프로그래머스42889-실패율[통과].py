import heapq
q = []
INF = -int(1e9)
#푸쉬 하려면 계속 이렇게 해야함


def solution(n,stages):
    answer = []
    array = [0] * (502)
    for i in stages:
        array[i] = array[i] + 1

    successStageNum = 0

    for i in range(1,n+1):
        # print("array[i] : ", array[i])
        # print("len(stages)-successStageNum", len(stages) - successStageNum)
        if len(stages) - successStageNum == 0:
            heapq.heappush(q, (0, i))
        else :
            failRate = array[i] / (len(stages) - successStageNum)
            # print("failRate", failRate)
            heapq.heappush(q, (-failRate, i))
        successStageNum += array[i]


    while q:
        answer.append(heapq.heappop(q)[1])

    return answer

# print(solution(5,[1,1]))
# print(solution(4,[4,4,4,4]))
# print(solution(5,[2,1,2,6,2,4,3,3]))
