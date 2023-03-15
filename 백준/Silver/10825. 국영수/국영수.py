import sys
si = sys.stdin.readline

n = int(si())

info = []

for _ in range(n):
    name, kor, eng, math = si().split()
    kor, eng, math = map(int, (kor, eng, math))
    info.append((name, kor, eng, math))

info.sort(key = lambda x: (-x[1], x[2], -x[3], x[0]))

for x in info:
    print(x[0])
