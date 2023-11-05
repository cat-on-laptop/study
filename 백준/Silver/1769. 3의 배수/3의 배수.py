s = input()

cnt = 0

while len(s) > 1:
    tot = 0
    for x in s:
        tot += int(x)
    
    s = str(tot)
    cnt += 1

print(cnt)
print("YES" if int(s) % 3 == 0 else "NO")