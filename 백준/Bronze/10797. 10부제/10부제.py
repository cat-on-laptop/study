a, arr, cnt = int(input()), list(map(int, input().split())), 0

for x in arr:
    if x % 10 == a: cnt += 1

print(cnt)


