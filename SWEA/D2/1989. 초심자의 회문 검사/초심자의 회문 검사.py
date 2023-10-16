n = int(input())

def is_pal(s : str) -> bool:
    if len(s) < 2:
        return True
    if(s[0] == s[-1]):
        return is_pal(s[1:-1])
    else:
        return False

for tc in range(1, n + 1):
    s = input().strip()
    print(f"#{tc} {1 if is_pal(s) == True else 0}")
