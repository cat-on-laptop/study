# 백준 9009
# 미리 피보나치 배열을 구하고
# 그리디하게 큰 수부터 n에서 빼고 넣어줌

import sys
si = sys.stdin.readline

dp = [0] * 50

dp[1] = dp[2] = 1

for i in range(3, 50):
    dp[i] = dp[i-1] + dp[i-2]

t = int(si())

for _ in range(t):
    n = int(si())
    arr = []
    for i in range(49, 1, -1):
        if n >= dp[i]:
            n -= dp[i]
            arr.append(dp[i])
    
    print(*arr[::-1])