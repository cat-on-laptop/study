# 백준 2133
# 전형 적인 dp
# 타일을 채우는 모양이 따라 분류
# dp의 과정에서 누적합이 필요하므로 이는 dp2로 해결하여 시간 복잡도 O(n)

n = int(input())

dp = [0] * 31
dp2 = [0] * 31


# base case
dp2[0] = dp[0] = 1
dp[2] = 3

for i in range(4, n + 1, 2):
    dp2[i - 2] = dp2[i - 4] + dp[i - 2]
    dp[i] = 3 * dp[i - 2] + 2 * dp2[i - 4]

print(dp[n])