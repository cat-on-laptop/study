import sys
from collections import deque
si = sys.stdin.readline

n, m = map(int, si().split())

arr = [[] for _ in range(n + 1)]

for _ in range(m):
    x, y = map(int, si().split())
    arr[y].append(x)

ans = []

def bfs(curr : int) -> int:
    visited = [False] * (n + 1)
    q = deque()
    cnt = 1
    visited[curr] = True
    q.append(curr)

    while q:
        curr = q.popleft()

        for x in arr[curr]:
            if not visited[x]:
                visited[x] = True
                q.append(x)
                cnt += 1

    return cnt

for i in range(1, n + 1):
    ans.append((bfs(i), i))

ans.sort(key = lambda x : (-x[0], x[1]))
temp = ans[0][0]

for x in ans:
    if x[0] == temp:
        print(x[1], end = ' ')