n, cnt = int(input()), 0
arr = [0] * n

def isOk() -> bool:
    idx = 0
    while idx < n:
        if idx + arr[idx] - 1 >= n:
            # 범위를 벗어나면 false
            return False
        for j in range(idx, idx + arr[idx]):
            # arr[j] 와 arr[idx] 비교
            if arr[j] != arr[idx]:
                return False
        # idx값 update
        idx += arr[idx]
    return True

def backtracking(curr : int) -> None:
    global cnt
    
    if curr == n:
        if isOk():
            cnt += 1
        return
    
    for i in range(1, 5):
        arr[curr] = i
        backtracking(curr + 1)

backtracking(0)
print(cnt)