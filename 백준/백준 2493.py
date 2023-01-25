# 백준 2493

import sys
from collections import deque

si = sys.stdin.readline

n = int(si())

arr = list(map(int, si().split()))

ans = [0] * n

stack = deque()

# stack의 맨 위에 있는 수 보다 stack의 아래에 있는 수가 더 큼
# stack의 맨 위에 있는 수가 stack의 아래이 있는 수보다 작으면 
# 이미 탑에서 수신했기 때문
# ex 7 1 인 경우 stack에 1이 왔다가 7을 만나므로 바로 pop됨
# 1 2 3 4 5 인 경우
# 5 4 3 2 1 인 경우 

for i in range(n - 1, -1, -1):
    if not stack:
        stack.append((arr[i], i))
    else:
        while stack and stack[-1][0] < arr[i]:
            val, idx = stack.pop()
            ans[idx] = i + 1
        stack.append((arr[i], i))

print(*ans)