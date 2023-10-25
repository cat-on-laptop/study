from collections import deque

def solution(s):
    st = deque()
    
    for x in s:
        if st and st[-1] == x:
            st.pop()
        else :
            st.append(x)
    
    return 0 if st else 1