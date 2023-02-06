k, n = map(int, input().split())

arr = [0] * n

def backtracking(curr : int) -> None:
    # arr의 curr index에 1 ~ k를 집어넣고 curr가 n이면 출력해주는 함수
    if curr == n:
        print(*arr)
        return
    
    for i in range(1, k + 1):
        arr[curr] = i
        backtracking(curr + 1)

backtracking(0)