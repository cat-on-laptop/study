def solution(quiz):
    answer = []
    
    for x in quiz:
        answer.append('O' if eval(x.split('=')[0]) == int(x.split('=')[1]) else 'X')

    return answer