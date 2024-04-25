def dfs(curr: int, tot:int, kcal:int)->None:
    global ans
    if kcal > l : return

    if curr == n : 
        ans = max(ans, tot)
        return

    dfs(curr + 1, tot + taste[curr], kcal + kal[curr]) 
    dfs(curr + 1, tot, kcal)


for test_case in range(int(input())):
    n, l = map(int, input().split())

    taste = []
    kal = []

    for _ in range(n):
        x, y = map(int, input().split())
        taste.append(x)
        kal.append(y)

    ans = 0
    dfs(0, 0, 0)

    print(f"#{test_case+1} {ans}")
