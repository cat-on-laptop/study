# 백준 4963

import sys
from collections import deque
si = sys.stdin.readline

def inRange(row : int, col : int) -> bool:
    global r, c
    return 0 <= row < r and 0 <= col < c


def bfs(row : int, col : int) -> None:
    q = deque()

    dir = ((-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1))

    q.append((row, col))
    while q:
        row, col = q.popleft()

        for dr, dc in dir:
            nr, nc = row + dr, col + dc
            if inRange(nr, nc) and arr[nr][nc] and not visited[nr][nc]:
                visited[nr][nc] = True
                q.append((nr, nc))


while True:
    c, r = map(int, si().split())
    if c == 0 and r == 0:
        break
    
    arr = [
        [int(x) for x in si().split()]
        for _ in range(r)
    ]


    visited = [
        [False] * c
        for _ in range(r)
    ]

    cnt = 0

    for i in range(r):
        for j in range(c):
            if arr[i][j] and not visited[i][j]:
                visited[i][j] = True
                cnt += 1
                bfs(i, j)
    
    print(cnt)
    