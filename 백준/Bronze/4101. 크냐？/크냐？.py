import sys
si = sys.stdin.readline

while True:
    x, y = map(int, si().split())

    if x == 0 and y == 0: break

    print('Yes' if x > y else 'No')