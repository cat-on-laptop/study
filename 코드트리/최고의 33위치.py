n = int(input())
arr = [
    list(map(int, input().split()))
    for _ in range(n)
]

def check(row : int, col : int) -> int:
    cnt = 0
    for i in range(3):
        for j in range(3):
            cnt += arr[row + i][col + j]
    return cnt

ans = -1

for i in range(n):
    if i + 2 >= n:
        continue
    for j in range(n):
        if j + 2 >= n:
            continue
        ans = max(ans, check(i, j))

print(ans)