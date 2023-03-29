import sys
sys.stdin = open('input.txt')
si = sys.stdin.readline
sys.setrecursionlimit(10**8)
n, k = map(int, si().split())
arr = [
    list(map(int, si().split()))
    for _ in range(n)
]
pos = (-1, -1)
def bs2d(key, rowL, rowR, colL, colR):
    global pos
    #print(rowL, rowR, colL, colR)
    # 재귀 탈출조건 1 matrix 크기가 1 by 1
    if rowL == rowR and colL == colR:
        if arr[rowL][colL] == key:
            pos = (rowL, colL)
        return
    # x, y를 구함
    i, j = (rowR + rowL) // 2, (colR + colL) // 2
    x, y = arr[i][j], arr[i+1][j+1]
    # print(rowL, rowR, colL, colR)
    # 재귀 탈출 조건 2 key를 찾은 경우
    if x == key:
        pos = (i, j)
        return
    if y == key:
        pos = (i + 1, j + 1)
        return
    if key < x:
        # 이 경우 4 사분면에는 존재하지 않음 -> 1,2,3 사분면에 대하여 탐색
        # 1 사분면에 대하여 탐색
        bs2d(key, rowL, i, j + 1, colR)
        # 2 사분면에 대하여 탐색
        bs2d(key, rowL, i, colL, j)
        # 3 사분면에 대하여 탐색
        bs2d(key, i + 1, rowR, colL, j)
    elif key > y:
        # 이 경우 2 사분면에는 존재하지 않음 -> 1, 3, 4 사분면에 대하여 탐색
        # 1 사분면에 대하여 탐색
        bs2d(key, rowL, i, j + 1, colR)
        # 3 사분면에 대하여 탐색
        bs2d(key, i + 1, rowR, colL, j)
        # 4 사분면에 대하여 탐색
        bs2d(key, i + 1, rowR, j + 1, colR)
    else :
        # 이 경우 2, 4 사분면에 존재하지 않음 -> 1, 3 사분면에 대하여 탐색
        # 1 사분면에 대하여 탐색
        bs2d(key, rowL, i, j + 1, colR)
        # 3 사분면에 대하여 탐색
        bs2d(key, i + 1, rowR, colL, j)
bs2d(k, 0, n - 1, 0, n - 1)
print(pos)
# (1, 2)
# arr
# 2 5 10 19
# 3 8 16 19
# 7 20 20 32
# 13 25 37 44