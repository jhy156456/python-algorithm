import heapq
import sys

input = sys.stdin.readline
# p = input()


def solution(p):
    answer = ''

    return answer


def split(p):
    print(p)
    one = 0
    zero = 0
    result = []
    endPoint = 0
    for i in range(len(p)):
        if p[i] == '(':
            one += 1
        else:
            zero += 1
        if one > 0 and zero > 0 and one == zero:
            one = 0
            zero = 0
            result.append((i+1 - endPoint, (endPoint+1, i + 1)))
            endPoint = i
    result.sort()
    return p[result[0][1][0]:result[0][1][1]]


def isRight(p):
    one = 0
    zero = 0
    for i in p:
        if i == '(':
            one += 1
        else:
            zero += 1
    return one == zero


print(split("))(()("))