n = int(input())
arr = [input() for _ in range(n)]
visited = [input() for _ in range(n)]
rst = [['.']*n for _ in range(n)]
boom = False

def cnt(row:int, col:int)->int:
    d = ((-1,0), (-1,1), (0,1), (1,1), (1,0), (1,-1), (0,-1), (-1,-1))

    tot = 0

    for dr, dc in d:
        nr, nc = row + dr, col + dc
        if nr < 0 or nr >= n or nc < 0 or nc >= n or arr[nr][nc] == '.':
            continue
        tot += 1

    return tot

for i in range(n):
    for j in range(n):
        if visited[i][j] == 'x' and arr[i][j] == '*':
            boom = True

for i in range(n):
    for j in range(n):
        if visited[i][j] == 'x' and arr[i][j] == '.': rst[i][j] = cnt(i,j)
        elif boom and arr[i][j] == '*': rst[i][j] = '*'


for row in rst:
    print(*row, sep='')