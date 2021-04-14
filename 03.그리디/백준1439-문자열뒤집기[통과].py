list = input()

count0 = 0
count1 = 0

if list[0] == '1':
    # 1이면 0으로  만들어야함

    count0 += 1
elif list[0] == '0':
    # 0이면 1로 만들어야함
    count1 += 1

for i in range(len(list) - 1):
    if list[i] != list[i + 1]:
        if list[i + 1] == '1':
            # 모두 0으로 만드는 경우
            # 다음 숫자가 1이면 0으로 만들어야함
            count0 += 1
        elif list[i + 1] == '0':
            # 모두 1으로 만드는 경우
            # 다음숫자가 0이면 1로 만들어야함
            count1 += 1
print(min(count0,count1))
