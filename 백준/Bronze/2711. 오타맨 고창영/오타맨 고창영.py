t = int(input())

for _ in range(t):
    idx, s = input().split()
    idx = int(idx)
    for i in range(len(s)):
        if i == idx - 1: continue
        print(s[i], end='')
    print()