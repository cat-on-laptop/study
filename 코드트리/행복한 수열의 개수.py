import sys
si = sys.stdin.readline

n, m = map(int, si().split())

arr = [
    list(map(int, si().split()))
    for _ in range(n)
]

ans = 0

def rowSearch(col : int) -> bool:
    cnt = 1
    for i in range(1, n):
        if arr[i][col] == arr[i - 1][col]:
            cnt += 1
            if cnt == m:
                return True
        else:
            cnt = 1
            
    return cnt >= m

def colSearch(row : int) -> bool:
    cnt = 1
    for i in range(1, n):
        if arr[row][i] == arr[row][i - 1]:
            cnt += 1
            if cnt == m:
                return True
        else:
            cnt = 1

    return cnt >= m

for i in range(n):
    # 가로 탐색
    if rowSearch(i):
        ans += 1
    if colSearch(i):
        ans += 1

print(ans)
        