from itertools import combinations

n,m  = map(int, input().split())

graph = [list(map(int, input().split())) for _ in range(n)]

chikhens = []
houses = []
for i in range(n):
    for j in range(n):
        if graph[i][j] == 2:
            chikhens.append((i,j))
        elif graph[i][j] == 1:
            houses.append((i,j))

chikhens = list(combinations(chikhens,m))
result = 100000000

for chikhen in chikhens:
    #조합으로 뽑힌 치킨집들을 비교해본다.
    sumAllHouseChikchenDist = 0

    for house in houses:
        houseX = house[0]
        houseY = house[1]
        minValue = 1000000000
        for i in range(m):
            curChikenX = chikhen[i][0]
            curChikenY = chikhen[i][1]
            minValue = min(minValue,abs(houseX-curChikenX) + abs(houseY-curChikenY))
        sumAllHouseChikchenDist += minValue
    result = min(sumAllHouseChikchenDist,result)

print(result)


