import sys
si = sys.stdin.readline

t = int(si())

for _ in range(t):
    n, m, k = map(int ,si().split())
    arr = list(map(int, si().split()))
    arr += arr

    l, r, temp, cnt = 0, 0, 0, 0
    while r < m:
        temp += arr[r]
        r += 1

    while l < n:
        if temp < k:
            cnt += 1
        temp -= arr[l]
        temp += arr[r]
        l += 1
        r += 1

    print(cnt if n != m else cnt // n)