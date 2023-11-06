import sys
si = sys.stdin.readline

n = int(si())
arr = list(map(int, si().split()))

for i in range(1, n):
    arr[i] += arr[i-1]

q = int(si())

for _ in range(q):
    a, b = map(int, si().split())
    a -= 1
    b -= 1
    
    print(arr[b] - arr[a - 1] if a > 0 else arr[b])
