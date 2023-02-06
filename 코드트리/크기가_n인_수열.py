n = int(input())

selected = [False] * (n + 1)
arr = [0] * n

def backtracking(curr : int) -> None:
    if curr == n:
        print(*arr)
        return

    for i in range(1, n + 1):
        if selected[i]: 
            continue

        selected[i] = True
        arr[curr] = i
        backtracking(curr + 1)
        selected[i] = False

backtracking(0)