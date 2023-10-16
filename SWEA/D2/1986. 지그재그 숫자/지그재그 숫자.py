n = int(input())

for tc in range(1, n + 1):
    x = int(input())
    tot = 0
    for i in range(1, x + 1):
        if i & 1: tot += i
        else : tot -= i
    print(f'#{tc} {tot}')