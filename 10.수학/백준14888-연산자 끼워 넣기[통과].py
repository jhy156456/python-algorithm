from itertools import permutations
import sys
input = sys.stdin.readline

n = int(input())
array = list(map(int, input().split()))
operatorCount = list(map(int, input().split()))
operators = []
operatorsPermutations = []
results = []
for i in range(4):
    for j in range(int(operatorCount[i])):
        if i ==0:
            operators.append("+")
        elif i == 1:
            operators.append("-")
        elif i == 2:
            operators.append("*")
        else :
            operators.append("/")

def operation(operator,a,b):
    if operator == "+":
        return a+b
    elif operator == "-":
        return a-b
    elif operator == "*":
        return a*b
    elif operator == "/":
        isMinus = False
        if a < 0 or b < 0:
            isMinus = True
        value = abs(a)//abs(b)
        if isMinus:
            return -value
        else :
            return value

operatorsPermutations = list(permutations(operators,len(operators)))
for i in range(len(operatorsPermutations)):
    operatorsPermutation = operatorsPermutations[i]
    operatedNumber = array[0]
    for j in range(1, len(array)):
        operatedNumber = operation(operatorsPermutation[j-1],operatedNumber,array[j])
    results.append(operatedNumber)

print(max(results))
print(min(results))



