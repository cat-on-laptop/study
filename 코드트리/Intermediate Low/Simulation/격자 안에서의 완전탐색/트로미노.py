import sys
si = sys.stdin.readline

n, m = map(int, si().split())
arr = [
    list(map(int, si().split()))
    for _ in range(n)
]

# block 배열에 미리 트로미노 모양을 만들어서 이를 활용해 탐색하자

block = (
    ((1,0,0),
    (1,1,0),
    (0,0,0)),

    ((0,1,0),
    (1,1,0),
    (0,0,0)),

    ((1,1,0),
    (1,0,0),
    (0,0,0)),

    ((1,1,0),
    (0,1,0),
    (0,0,0)),

    ((1,1,1),
    (0,0,0),
    (0,0,0)),

    ((1,0,0),
    (1,0,0),
    (1,0,0)),
)


def check(row : int, col : int) -> int:
    cnt = 0
    for k in range(6):
        # 6개의 트리미노에 대하여 row, col 을 좌상단으로 하는 모양으로 탐색
        temp = 0
        flag = True
        for i in range(3):
            for j in range(3):
                if block[k][i][j] == 0:
                    # block가 0이라면 볼 필요가 없으니 그 부분은 continue로 넘어감
                    continue
                if row + i >= n or col + j >= m:
                    # block이 격자의 범위를 벗어나는 경우는 생각하지 않으므로 flag 변수 활용
                    flag = False
                else :
                    # 트리미노의 모양이 1 이면서 격자의 범위 내라면 temp에 더해줌
                    temp += arr[row + i][col + j]
        if flag:
            # 가능하다면 값을 update!
            cnt = max(cnt, temp)
    return cnt

ans = 0

for i in range(n):
    for j in range(m):
        ans = max(ans, check(i, j))

print(ans)