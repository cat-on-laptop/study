n = int(input())

arr = [list(map(int, input().split())) for _ in range(n)]
dir = ((1, 0), (-1, 0), (0, 1), (0, -1))

def inRange(row : int, col : int) -> bool:
    return 0 <= row < n and 0 <= col < n

def boom(row : int, col : int) -> None:
    # 중심 위치를 주면 중심 위치에 있는 수만큼 십자로 폭탄을 터트리는 함수

    cnt = temp[row][col] 
    temp[row][col] = 0

    for i in range(1, cnt):
        for dr, dc in dir:
            nr, nc = row + i*dr, col + i*dc
            if inRange(nr, nc):
                temp[nr][nc] = 0

def fall() -> None:
    # arr을 보고 중력에 의해 떨어뜨리는 함수
    for i in range(n):
        temp1 = [0] * n
        end_of_temp = 0
        for j in range(n-1, -1, -1):
            if temp[j][i] != 0:
                temp1[end_of_temp] = temp[j][i]
                end_of_temp += 1
        # arr을 열을 기준으로 보고 폭탄에 살아남은 부분을 temp에 추가, 길이는 end_of_temp를 통해 관리

        # 임시변수 cnt를 두고 cnt가 end_of_temp 보다 작은 경우 arr의 col 행에 밑에서부터 추가
        cnt = 0
        for j in range(n-1, -1, -1):
            if cnt < end_of_temp:
                temp[j][i] = temp1[cnt]
                cnt += 1
            else:
                temp[j][i] = 0

def check() -> int:
    cnt = 0
    visited = [[False] * n for _ in range(n)]

    for i in range(n):
        for j in range(n):
            if temp[i][j] == 0:
                continue
            for dr, dc in dir:
                nr, nc = i + dr, j + dc
                if inRange(nr, nc) and not visited[nr][nc] and temp[nr][nc] == temp[i][j]:
                    # 범위 내애 있고, 새로운 지점을 방문하지 않았고 값이 같다면
                    visited[nr][nc] = True
                    visited[i][j] = True
                    # visited[i][j] 도 True로 하는 이유는 nr이 i, nc가 j가 되는 경우 기존 위치가 False이므로 중복 카운팅
                    cnt += 1
    return cnt 
cnt = 0

for i in range(0, n):
    for j in range(0, n):
        temp = [arr[x][:] for x in range(n)]

        boom(i, j)
        fall()

        cnt = max(cnt, check())

print(cnt)