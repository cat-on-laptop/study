n, m, q = map(int, input().split())

arr = [
    list(map(int, input().split()))
    for _ in range(n)
]

def shift(row : int, dir : chr) -> None:
    # 바람의 방향과 row가 오면 shift 시키는 함수
    if dir == 'R':
        temp = arr[row][0]
        for i in range(m-1):
            arr[row][i] = arr[row][i+1]
        arr[row][m-1] = temp

    else:
        temp = arr[row][m-1]
        for i in range(m-1, 0, -1):
            arr[row][i] = arr[row][i-1]
        arr[row][0] = temp

def flip(dir : chr) -> chr:
    # 방향을 반전시키는 함수
    return 'R' if dir == 'L' else 'L'

def check(r1 : int, r2 : int) -> bool:
    # r1 행과 r2 행에 같은 숫자가 있으면 true 리턴해주는 함수
    for i in range(m):
        if arr[r1][i] == arr[r2][i]:
            return True

    return False

# simulate
for _ in range(q):
    # input
    row, dir = input().split()
    row = int(row); row -= 1

    shift(row, dir)

    # 위로 전파
    tempDir = flip(dir)
    for r in range(row - 1, -1, -1):
        if not check(r, r + 1):
            break
        shift(r, tempDir)
        tempDir = flip(tempDir)

    # 아래로 전파
    tempDir = flip(dir)
    for r in range(row + 1, n):
        if not check(r, r - 1):
            break
        shift(r, tempDir)
        tempDir = flip(tempDir)

for i in range(n):
    print(*arr[i])