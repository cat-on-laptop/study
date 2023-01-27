# 백준 1182

import sys
# sys.stdin = open("./test/input.txt", "r")

si = sys.stdin.readline

n, s = map(int, si().split())
arr = list(map(int, si().split()))
cnt = 0

def backtrack(curr : int, val : int, flag : bool) -> None:
    global cnt
    if curr == n:
        if flag and val == s:
            cnt += 1
        return

    # 선택
    backtrack(curr + 1, val + arr[curr], True)
    # 선택 x
    backtrack(curr + 1, val, flag)

backtrack(0, 0, False)
print(cnt)
