# input
n = int(input())

arr = [
    list(map(int, input().split()))
    for _ in range(n)
]

r, c = map(int, input().split())
r -= 1; c -= 1;

def inRange(row : int, col : int) -> bool:
    return 0 <= row < n and 0 <= col < n

def boom(row : int, col : int) -> None:
    # 중심 위치를 주면 중심 위치에 있는 수만큼 십자로 폭탄을 터트리는 함수
    dir = ((1, 0), (-1, 0), (0, 1), (0, -1))

    cnt = arr[row][col] 
    arr[row][col] = 0

    for i in range(1, cnt):
        for dr, dc in dir:
            nr, nc = row + i*dr, col + i*dc
            if inRange(nr, nc):
                arr[nr][nc] = 0

def fall() -> None:
    # arr을 보고 중력에 의해 떨어뜨리는 함수
    for i in range(n):
        temp = [0] * n
        end_of_temp = 0
        for j in range(n-1, -1, -1):
            if arr[j][i] != 0:
                temp[end_of_temp] = arr[j][i]
                end_of_temp += 1
        # arr을 열을 기준으로 보고 폭탄에 살아남은 부분을 temp에 추가, 길이는 end_of_temp를 통해 관리

        # 임시변수 cnt를 두고 cnt가 end_of_temp 보다 작은 경우 arr의 col 행에 밑에서부터 추가
        cnt = 0
        for j in range(n-1, -1, -1):
            if cnt < end_of_temp:
                arr[j][i] = temp[cnt]
                cnt += 1
            else:
                arr[j][i] = 0

# simulation
boom(r, c)
fall()

# output
for i in range(n):
    print(*arr[i])