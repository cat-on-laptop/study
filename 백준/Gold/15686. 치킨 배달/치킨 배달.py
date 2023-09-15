import sys
si = sys.stdin.readline

n, k = map(int, si().split())
arr = [list(map(int, si().split())) for _ in range(n)]

house = []
store = []
for i in range(n):
    for j in range(n):
        if arr[i][j] == 1:
            house.append((i, j))
        elif arr[i][j] == 2:
            store.append((i, j))



m = len(store)

def calc(candidiate : list) -> int:
    tot = 0
    for row, col in house:
        d = 10000
        for r, c in candidiate:
            d = min(d, abs(row - r) + abs(col - c))
        tot += d

    return tot
ans = 21e8

a = []

def backtracking(curr : int, cnt : int) -> None:
    global ans

    if cnt == k:
        ans = min(ans, calc(a))
        return

    if curr == m:
        return

    # select
    a.append(store[curr])
    backtracking(curr + 1, cnt + 1)

    a.pop()
    backtracking(curr+1, cnt)

backtracking(0, 0)
print(ans)
