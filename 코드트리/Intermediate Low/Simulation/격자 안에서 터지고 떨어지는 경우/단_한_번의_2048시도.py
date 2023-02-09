# input
arr = [
    list(map(int, input().split()))
    for _ in range(4)
]

dir = input()
n = 4 # 일반화를 위해 n으로 설정

def rotate() -> None:
    # arr을 시계방향으로 회전하는 함수
    
    temp = [[0] * n for _ in range(n)]

    for row in range(n):
        for col in range(n):
            temp[col][n-1-row] = arr[row][col]

    # temp를 arr로 복사
    for i in range(4):
        arr[i] = temp[i][:]

def drop() -> None:
    temp = [[0] * n for _ in range(n)]
    # 떨굴 배열 temp

    for col in range(n):
        pass


mapper = {'R':1, 'D':0, 'L':3, 'U':2}
# 90도 회전 횟수