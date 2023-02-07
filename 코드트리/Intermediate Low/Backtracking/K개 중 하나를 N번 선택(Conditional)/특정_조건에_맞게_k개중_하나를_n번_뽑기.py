k, n = map(int, input().split())
arr = [0] * n

def backtracking(curr : int) -> None:
    if curr == n:
        print(*arr)
        return

    for i in range(1, k + 1):
        if curr >= 2 and arr[curr-1] == i and arr[curr-2] == i:
            continue
        arr[curr] = i
        backtracking(curr+1)

backtracking(0)