import sys
si = sys.stdin.readline

# input
n, m = map(int, si().split())
arr = [
    list(map(int, si().split()))
    for _ in range(n)
]


# 채굴 비용 리턴해주는 함수
def price(k : int) -> int:
    return (k + 1) ** 2 + k ** 2

# 채굴 할 수 있는 금의 갯수를 반환하는 함수
def mine(row : int, col : int, k : int) -> int:
    # 중심이 row, col 이면서 size 가 k인 마름모
    cnt = 0
    for i in range(n):
        for j in range(n):
            # i, j는 격자 내부의 점이고 마름모의 정의 활용하여 거리 계산하여
            # k이하면 갯수 카운트
            if abs(i - row) + abs(j - col) <= k:
                cnt += arr[i][j]

    return cnt

# simulate
ans = 0

for i in range(n):
    for j in range(n):
        for k in range(((n - 1) << 1) + 1):
            cnt = mine(i, j, k)
            if cnt * m >= price(k):
                ans = max(cnt, ans)

print(ans)