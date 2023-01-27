# 백준 1976

import sys
# sys.stdin = open("./test/input.txt", "r")

si = sys.stdin.readline

n, m = int(si()), int(si())

parent = [i for i in range(n + 1)]

def find(x : int) -> int:
    if parent[x] == x:
        return x
    parent[x] = find(parent[x])
    return parent[x]

def union(x : int, y : int) -> None:
    # x를 y의 밑으로
    px, py = find(x), find(y)
    parent[px] = py

for i in range(1, n + 1):
    arr = list(map(int, si().split()))
    for j in range(n):
        if arr[j] == 1:
            union(i, j + 1)

plan = list(map(int, si().split()))

flag = True
for i in range(1, m):
    if find(plan[i-1]) != find(plan[i]):
        flag = False
        break

print("YES" if flag else "NO")

