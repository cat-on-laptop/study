n, m = map(int, input().split())

selected = [False] * (n + 1)
arr = [0] * m

def backtracking(curr : int) -> None:
    if curr == m:
        print(*arr)
        return

    for i in range(1, n + 1):
        if selected[i] or curr > 0 and arr[curr-1] >= i:
            continue
        selected[i] = True
        arr[curr] = i
        backtracking(curr + 1)
        selected[i] = False

backtracking(0)