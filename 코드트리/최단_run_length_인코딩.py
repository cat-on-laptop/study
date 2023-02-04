s = input()

def encoding(s : str) -> str:
    # 주어진 문자열에 대하여 Run Length encoding을 반환하는 함수
    cnt = 1
    rst = ""
    for i in range(1, len(s)):
        if s[i-1] != s[i]:
            rst += s[i-1]
            rst += str(cnt)
            cnt = 1
        
        else:
            cnt += 1

    rst += s[-1]
    rst += str(cnt)

    return rst

def shift(s : str, length : int) -> str:
    # length 만큼 문자열 s를 오른쪽으로 shift 해 결과를 리턴하는 함수
    # aabb 1 -> baab
    for _ in range(length):
        s = s[-1] + s[:len(s) - 1]
    return s

ans = 20

# 모든 경우의 수에 대하여 완전 탐색
for i in range(1, len(s) + 1):
    ans = min(ans, len(encoding(shift(s, i))))

print(ans)