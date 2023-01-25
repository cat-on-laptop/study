# 백준 5347

import sys
si = sys.stdin.readline

t = int(si())

def gcd(x : int, y : int) -> int:
    if y == 0:
        return x
    return gcd(y, x % y)

def lcm(x : int, y : int) -> int:
    t = gcd(x, y)
    return x * y // t

for _ in range(t):
    a, b = map(int, si().split())
    print(lcm(a, b))