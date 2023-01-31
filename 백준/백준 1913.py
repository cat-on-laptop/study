# 백준 1913

n = int(input())
k = int(input())

arr = [
    [0] * n
    for _ in range(n)
]

def inRange(row : int, col : int) -> bool:
    return 0 <= row < n and 0 <= col < n

dir = ((1, 0), (0, 1), (-1, 0), (0, -1))

row = col = d = 0
aRow = aCol = 0
for i in range(n ** 2, 0, -1):
    arr[row][col] = i
    if i == k:
        aRow, aCol = row, col
    nr, nc = row + dir[d][0], col + dir[d][1]

    if not inRange(nr, nc) or arr[nr][nc]:
        d = (d + 1) & 3

    nr, nc = row + dir[d][0], col + dir[d][1]

    row, col = nr, nc

for i in range(n):
    print(*arr[i])
print(aRow + 1, aCol + 1)