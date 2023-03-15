import sys
from collections import deque
si = sys.stdin.readline

n = int(si())
q = deque()

for _ in range(n):
    op = si().split()

    if op[0] == 'push':
        q.append(op[1])
    
    elif op[0] == 'pop':
        if q:
            print(q.popleft())
        else:
            print(-1)

    elif op[0] == 'size':
        print(len(q))
    
    elif op[0] == 'empty':
        print(0 if q else 1)
    
    elif op[0] == 'front':
        print(q[0] if q else -1)
        
    else:
        print(q[-1] if q else -1)