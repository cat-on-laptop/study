# 백준 9020

import sys
si = sys.stdin.readline

prime = [False] * 10001

# 에라토스테네스의 체

prime[0] = prime[1] = True
i = 2

while i * i <= 10000:
    if not prime[i]:
        for j in range(i * i, 10001, i):
            prime[j] = True
    i += 1

t = int(si())

for _ in range(t):
    n = int(si())
    temp = n >> 1
    for i in range(temp, 1, -1):
        if not prime[i] and not prime[n - i]:
            print(i, n - i)
            break