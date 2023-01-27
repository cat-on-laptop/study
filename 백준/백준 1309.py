# 백준 1309

import sys
sys.stdin = open("./test/input.txt", "r")

si = sys.stdin.readline

n = int(si())

dp = [[0, 0, 0] for _ in range(100000)] # 0 : 배치 x 1 : 좌에 배치 2 : 우에 배치

dp[0][0] = dp[0][1] = dp[0][2] = 1

for i in range(1, n):
    dp[i][0] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2]) % 9901
    dp[i][1] = (dp[i-1][0] + dp[i-1][2]) % 9901
    dp[i][2] = (dp[i-1][0] + dp[i-1][1]) % 9901

print(sum(dp[n-1]) % 9901)