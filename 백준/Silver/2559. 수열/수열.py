import sys
si = sys.stdin.readline

n, k = map(int, si().split())
arr = list(map(int, si().split()))

ans = -100000000

temp = 0

for i in range(0, k):
    temp += arr[i]
ans = max(temp, ans)

l, r = 0, k
while(r < n):
    temp -= arr[l]
    temp += arr[r]
    ans = max(ans, temp)
    l += 1; r += 1

print(ans)