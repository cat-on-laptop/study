# input
n = int(input())
end = n 
arr = [
    input()
    for _ in range(n)
]

# simulation
for _ in range(2):
    s, e = map(int ,input().split())
    s -= 1; e -= 1

    length = e - s + 1

    # 없애는 구간의 길이만큼 배열에서 당겨줌
    for i in range(e + 1, end):
        arr[i - length] = arr[i]
    
    end -= length

# output
print(end)
for i in range(end):
    print(arr[i])