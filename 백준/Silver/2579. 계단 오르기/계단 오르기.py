n = int(input())
arr = [int(input()) for _ in range(n)]
dp = [0] * n

for i in range(n):
    if i == 0: # basecase
        dp[i] = arr[0]
    elif i == 1: # basecase
        dp[i] = dp[0] + arr[1]
    elif i == 2: # basecase
        dp[i] = arr[i] + max(arr[i-1], arr[i-2])
    else:
        dp[i] = arr[i] + max(arr[i-1]+dp[i-3], dp[i-2])
        # 직전 칸을 밟는 경우 -> 3칸 연속 안되니 3번째 칸의 dp값 + 1번 전칸 점수
        # 2번째 전 칸을 밟는 경우 -> dp[i-2]

print(dp[-1])