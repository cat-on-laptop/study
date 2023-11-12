import sys
si = sys.stdin.readline

n, m = map(int, si().split())
arr = set()

for _ in range(n):
    arr.add(si().rstrip())

for _ in range(m):
    target = si().rstrip().split(',')
    for x in target:
        if x in arr:
            arr.remove(x)

    print(len(arr))