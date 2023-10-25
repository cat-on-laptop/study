def solution(strArr):
    answer = []
    for x in strArr:
        if 'ad' not in x:
            answer.append(x)
    return answer