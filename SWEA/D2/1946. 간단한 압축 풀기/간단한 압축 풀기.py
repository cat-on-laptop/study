testCase = int(input())

for t in range(1, testCase + 1):
    n = int(input())
    rst = ""
    for _ in range(n):
        x, l = input().split()
        l = int(l)
        rst += x*l

    n = len(rst)
    print(f'#{t}')
    for i in range(n):
        if i != 0 and i % 10 == 0:
            print('\n', rst[i], sep='', end='')
        else:
            print(rst[i], end='')
    print()
