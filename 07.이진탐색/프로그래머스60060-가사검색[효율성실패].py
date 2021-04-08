def solution(words, queries):
    answer = []
    for query in queries:
        # query = fro??, ~~
        eachQueryResult = 0
        for word in words:
            # word = frodo, ~~
            check = True
            # print("word : ", word)
            if len(word) != len(query):
                continue
            for i in range(len(query)):
                # 한글자씩 비교
                # print("query", query, "query[i]", query[i], "word[i]", word[i])
                if query[i] == '?': continue
                if word[i] != query[i]:
                    check = False
                    break
            if check:
                eachQueryResult += 1
        answer.append(eachQueryResult)

    return answer


# print(solution(["frodo", "front", "frost", "frozen", "frame", "kakao"],["fro??", "????o", "fr???", "fro???", "pro?"]))
print(solution(["frodo", "front", "frost", "frozen", "frame", "kakao"],
               ["fro??", "????o", "fr???", "fro???", "pro?"]))
