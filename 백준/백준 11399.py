# 백준 11399
# idea : 정렬 후 누적합
# 가장 적게 시간이 걸리는 사람을 먼저 수행시킴!

import sys
si = sys.stdin.readline

n = int(si())
arr = list(map(int, si().split()))

arr.sort()

for i in range(1, n):
    arr[i] += arr[i - 1]

print(sum(arr))