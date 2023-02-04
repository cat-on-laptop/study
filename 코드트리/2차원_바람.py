n, m, q = map(int, input().split())

arr = [
    list(map(int ,input().split()))
    for _ in range(n)
]

def shift(r1 : int, c1 : int, r2 : int, c2 : int) -> None:
    # r1, c1을 좌사당 r2, c2를 우하단으로 하는 직사각형을 
    # 시계방향으로 회전하는 함수

    # 위를 오른쪽으로 shift
    temp = arr[r1][c2]
    for i in range(c2, c1, -1):
        arr[r1][i] = arr[r1][i-1]

    # 오른쪽을 아래로 shift
    temp2 = arr[r2][c2]
    for i in range(r2, r1 + 1, -1):
        arr[i][c2] = arr[i-1][c2]
    arr[r1+1][c2] = temp

    # 아래를 왼쪽으로 shift
    temp = arr[r2][c1]
    for i in range(c1, c2 - 1):
        arr[r2][i] = arr[r2][i+1]
    arr[r2][c2-1] = temp2

    # 왼쪽을 위로 shift
    for i in range(r1, r2):
        arr[i][c1] = arr[i+1][c1]
    arr[r2-1][c1] = temp

def inRange(row : int, col : int) -> bool:
    return 0 <= row < n and 0 <= col < m

def modify(r1 : int, c1 : int, r2 : int, c2 : int) -> None:
    temp  = [
        [0] * m
        for _ in range(n)
    ]

    dir = ((-1, 0), (1, 0), (0, -1), (0, 1))

    # (r1, c1), (r2, c2) 범위의 숫자들을 더해서 평균값으로 나눠 temp에 저장
    for row in range(r1, r2 + 1):
        for col in range(c1, c2 + 1):
            cnt = 1
            temp[row][col] += arr[row][col]
            for dr, dc in dir:
                nr, nc = row + dr, col + dc
                if inRange(nr, nc):
                    temp[row][col] += arr[nr][nc]
                    cnt += 1
            temp[row][col] = temp[row][col] // cnt

    # (r1, c1), (r2, c2) 범위의의 temp에 저장된 값을 arr로 복사
    for row in range(r1, r2 + 1):
        for col in range(c1, c2 + 1):
            arr[row][col] = temp[row][col]

# simulation
for _ in range(q):
    r1, c1, r2, c2 = map(int, input().split())
    r1 -= 1; c1 -= 1; r2 -= 1; c2 -= 1
    
    shift(r1, c1, r2, c2)
    modify(r1, c1, r2, c2)

# output
for i in range(n):
    print(*arr[i])