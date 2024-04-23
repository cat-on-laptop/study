import sys
from collections import deque

si = sys.stdin.readline

n, m = map(int,si().split())
arr = [0] * 101
visited = [False] * 101

ladder = dict()
snake = dict()

for _ in range(n):
    x, y = map(int, si().split())
    ladder[x] = y

for _ in range(m):
    x, y = map(int, si().split())
    snake[x] = y

q = deque()
q.append(1)
visited[1] = True

while q:
    curr = q.popleft()

    if curr == 100:
        break

    for x in range(1, 7):
        temp = curr + x

        if temp <= 100 and not visited[temp]:
            if temp in ladder:
                temp = ladder[temp]
            elif temp in snake:
                temp = snake[temp]
            
            if not visited[temp]:
                visited[temp] = True
                arr[temp] = arr[curr] + 1
                q.append(temp)

print(arr[100])