from collections import defaultdict
import sys

si = sys.stdin.readline
n = int(si())
arr = list(map(int, si().split()))
cnt, history = 0, defaultdict(int)

for x in arr:
    if history[x] != 0:
        cnt += 1
    else :
        history[x] += 1

print(cnt)
