n, m = map(int, input().split())
arr = [int(input()) for _ in range(n)]

def unique() -> bool:
    # arr에 중복된 원소가 있으면 true리턴 없으면 false리턴하는 함수
    cnt = 1
    for i in range(1, n):
        if arr[i-1] == arr[i]:
            cnt += 1
        else:
            cnt = 1
        if cnt == m:
            return True

    return n >= 1 and cnt == m

def erase() -> None:
    global n
    # arr에서 m개 이상 중복된 원소의 값을 지워주고 arr의 size인 n도 관리하는 함수
    temp = [0] * n
    end_of_temp, cnt = 0, 1

    # m개 이상 중복된 수가 아닌 경우 temp에 옮겨 그걸 다시 arr로 복사
    for i in range(1, n):
        if arr[i-1] == arr[i]:
            cnt += 1
        else:
            if cnt < m:
                for k in range(cnt):
                    temp[end_of_temp] = arr[i-1]
                    end_of_temp += 1
            cnt = 1
    if cnt < m:
        for k in range(cnt):
            temp[end_of_temp] = arr[n-1]
            end_of_temp += 1
    
    for i in range(end_of_temp):
        arr[i] = temp[i]

    n = end_of_temp

# simulation
while unique():
    erase()

# output
print(n)
for i in range(n):
    print(arr[i])