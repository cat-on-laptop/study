import sys
from collections import deque
si = sys.stdin.readline

n = int(si())

arr = [
    list(int(x) for x in si().rstrip())
    for _ in range(n)
]

visited = [
    [False] * n 
    for _ in range(n)
]

def inRange(row : int, col : int) -> bool:
    return 0 <= row < n and 0 <= col < n

ans = []

def bfs(row : int, col : int) -> int:
    dir = ((-1, 0), (1, 0), (0, 1), (0, -1))
    visited[row][col] = True
    q = deque()
    q.append((row, col))
    cnt = 0
    while q:
        row, col = q.popleft()
        cnt += 1
        for dr, dc in dir:
            nr, nc = row + dr, col + dc
            if inRange(nr, nc) and not visited[nr][nc] and arr[nr][nc]:
                visited[nr][nc] = True
                q.append((nr, nc))

    return cnt

for row in range(n):
    for col in range(n):
        if arr[row][col] and not visited[row][col]:
            ans.append(bfs(row, col))

print(len(ans))
print(*sorted(ans), sep = '\n')
