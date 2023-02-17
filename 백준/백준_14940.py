import sys
from collections import deque
si = sys.stdin.readline

# input
n, m = map(int ,si().split())
row = col = 0
arr = [list(map(int, si().split())) for _ in range(n)]
dist = [[0] * m for _ in range(n)]\

# 시작 지점 찾기
for i in range(n):
    for j in range(m):
        if arr[i][j] == 2:
            row, col = i, j
            break

visited = [[False] * m for _ in range(n)]

dir = ((-1, 0), (1, 0), (0, -1), (0, 1))

def inRange(row : int, col : int) -> bool:
    return 0 <= row < n and 0 <= col < m

def bfs(row : int, col : int) -> None:
    q = deque()
    q.append((row, col, 0))
    visited[row][col] = True
    
    while q:
        row, col, d = q.popleft()
        for dr, dc in dir:
            nr, nc = row + dr, col + dc

            if inRange(nr, nc) and not visited[nr][nc] and arr[nr][nc] == 1:
                visited[nr][nc], dist[nr][nc] = True, d + 1
                q.append((nr, nc, d + 1))

bfs(row, col)

for i in range(n):
    for j in range(m):
        if arr[i][j] == 1 and not visited[i][j]:
            dist[i][j] = -1

# output
for x in dist:
    print(*x)