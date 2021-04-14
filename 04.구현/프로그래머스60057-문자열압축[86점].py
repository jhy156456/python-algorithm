def solution(hi):
    answer = 0
    resultLength = []
    for cutLength in range(1,len(hi)):
        a = {}
        prevString = ''
        length = 0
        for j in range(0,len(hi),cutLength):
            cutString = hi[j:j+cutLength]
            if cutString in a:
                if prevString != cutString:
                    length += cutLength
                    prevString = cutString
                    continue
                a[cutString] = a[cutString]+1
            else :
                a[cutString] = 1
            prevString = cutString
        for k in a:
            if a[k] >1:
                length += len(str(a[k])) + len(k)
            else:
                length += len(k)
        resultLength.append(length)

        # if isMerge :
        #     # 합쳐졌던게 있으면
        # else :
        #     # 합쳐졌던게 없으면
        #     resultLength.append(len(hi))
    if len(resultLength) == 0 : return  1
    else : return min(resultLength)


# print(solution("ababcdcdababcdcd"))
# print(solution("abcabcabcabcdededededede"))
# print(solution("aaaaaaaaaabbbbbbbbbb"))
# print(solution("xababcdcdababcdcd"))
# print(solution("abcabcdede"))
print(solution("aaaaaaaaaabbbbbbbbbb"))
