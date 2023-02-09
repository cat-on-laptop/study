from collections import deque

n, m = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(n)]
visited = [[0] * m for _ in range(n)]

def inRange(row : int, col : int) -> bool:
    return 0 <= row < n and 0 <= col < m

def bfs(row : int, col : int) -> None:
    dir = ((-1, 0), (1, 0), (0, -1), (0, 1))
    q = deque()
    q.append((row, col))
    visited[row][col] = 1
    while q:
        row, col = q.popleft()
        for dr, dc in dir:
            nr, nc = row + dr, col + dc
            if inRange(nr, nc) and not visited[nr][nc] and arr[nr][nc]:
                visited[nr][nc] = 1
                q.append((nr, nc))

bfs(0, 0)
print(visited[n-1][m-1])