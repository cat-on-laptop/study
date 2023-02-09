import sys
sys.setrecursionlimit(int(1e5))
si = sys.stdin.readline

n, m = map(int, si().split())

arr = [list(map(int, si().split())) for _ in range(n)]
visited = [[False] * m for _ in range(n)]

def inRange(row : int, col : int) -> bool:
    return 0 <= row < n and 0 <= col < m

def dfs(row : int, col : int) -> None:
    dir = ((1, 0), (0, 1))
    visited[row][col] = True

    for dr, dc in dir:
        nr, nc = row + dr, col + dc
        if inRange(nr, nc) and arr[nr][nc] and not visited[nr][nc]:
            dfs(nr, nc)

dfs(0, 0)

print(1 if visited[n-1][m-1] else 0)