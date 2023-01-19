import sys
from collections import deque
# sys.stdin = open('input.txt', 'r')

si = sys.stdin.readline

t = int(si())
row, col = 0, 0

def inRange(_row : int, _col : int) -> bool:
    global row, col
    return 0 <= _row < row and 0 <= _col < col

def bfs(row : int, col : int) -> None:
    q = deque()
    q.append((row, col))

    dir = ((-1, 0), (1, 0), (0, -1), (0, 1))

    while q:
        r, c = q.popleft()
        for dr, dc in dir:
            nr, nc = r + dr, c + dc
            if inRange(nr, nc) and not visited[nr][nc] and arr[nr][nc]:
                visited[nr][nc] = True
                q.append((nr, nc))


for _ in range(t):
    col, row, k = map(int, si().split())
    
    arr = [
        [False] * col 
        for _ in range(row)
    ]

    visited = [
        [False] * col 
        for _ in range(row)
    ]

    for _ in range(k):
        c, r = map(int, si().split())
        arr[r][c] = True

    cnt = 0

    for i in range(row):
        for j in range(col):
            if not visited[i][j] and arr[i][j]:
                visited[i][j] = True
                cnt += 1
                bfs(i, j)

    print(cnt)