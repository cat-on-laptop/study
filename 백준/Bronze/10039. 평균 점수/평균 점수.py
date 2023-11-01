import sys
si = sys.stdin.readline

tot = 0

for _ in range(5):
    score = int(si())
    tot += score if score >= 40 else 40

print(tot//5)