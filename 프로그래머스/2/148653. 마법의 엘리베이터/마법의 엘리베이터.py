def solution(storey):
    answer = 0
    
    while storey > 0:
        
        offset = storey % 10
        if offset < 5:
            answer += offset

        elif offset > 5:
            answer += 10 - offset
            storey += 10
            
        else:
            if (storey % 100) // 10 >= 5:
                storey += 10
            answer += 5
            
        storey //= 10            
        
    
    return answer