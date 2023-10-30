import sys
si = sys.stdin.readline

arr = (1,1,2,2,2,8)
req = tuple(map(int, si().split()))

for x, y in zip(arr, req):
    print(x-y, end=' ')