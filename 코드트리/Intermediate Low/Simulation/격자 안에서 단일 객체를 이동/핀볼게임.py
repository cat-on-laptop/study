n = int(input())
arr = [list(map(int, input().split())) for _ in range(n)]

dir = ((-1, 0), (1, 0), (0, -1), (0, 1))

def inRange(row : int, col : int) -> bool:
    return 0 <= row < n and 0 <= col < n

def simulate(row : int, col : int, d : int) -> int:
    cnt = 1
    while inRange(row, col):
        # 격자 내부에 존재하면

        # 방향 전환
        if arr[row][col] == 1:
            d = d ^ 3
        elif arr[row][col] == 2:
            d = d ^ 2
            
        row, col = row + dir[d][0], col + dir[d][1]
        # 방향으로 전진
        if not inRange(row, col):
            break
        

        cnt += 1
    return cnt + 1

ans = 0
# 아래 방향에 대해여 탐색
for i in range(n):
    ans = max(simulate(0, i, 1), ans)

# 위 방향에 대하여 탐색
for i in range(n):
    ans = max(simulate(n-1, i, 0), ans)

# 왼쪽 방향에 대하여 탐색
for i in range(n):
    ans = max(simulate(i, n-1, 2), ans)

# 오른쪽 방향에 대하여 탐색
for i in range(n):
    ans = max(simulate(i, 0, 3), ans)

print(ans)