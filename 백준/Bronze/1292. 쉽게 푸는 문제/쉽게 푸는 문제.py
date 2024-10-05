a, b = map(int, input().split())
arr = [0] # 0부터 시작해서 1, 3구간일 시 1 - 1 = 0, 0을 빼서 구간이 전체적으로 구해지 도록.

for i in range(1, 50): # 1 + 2 + 3 + 4 -> 등차 수열 -> n(n+1)/2 <= 1000
    for j in range(i):
        arr.append(i)

for i in range(1, 1001):
    arr[i] += arr[i-1]

print(arr[b] - arr[a-1])

