import sys
si = sys.stdin.readline

X = int(si())
n = int(si())

tot = 0
for _ in range(n):
    x, y = map(int, si().split())
    tot += x * y

if tot == X : print("Yes")
else : print("No")