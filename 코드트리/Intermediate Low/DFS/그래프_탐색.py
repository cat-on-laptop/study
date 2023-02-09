import sys
si = sys.stdin.readline

n, m = map(int, si().split())

arr = [[0] * n for _ in range(n)]
visited = [False] * n
cnt = 0

for _ in range(m):
    s, e = map(int, si().split())
    s -= 1; e -= 1
    arr[s][e] = arr[e][s] = 1


def dfs(curr : int) -> None:
    global cnt
    
    for i in range(n):
        if arr[curr][i] and not visited[i]:
            visited[i] = True
            cnt += 1
            dfs(i)

visited[0] = True
dfs(0)

print(cnt)

# dfs 자체가 방문한 노드의 수를 리턴해주는 함수로 짰을 경우
# 
# def dfs(vertex):
#     count = 1
#     for curr_v in graph[vertex]:
#         if not visited[curr_v]:
#             visited[curr_v] = True
#             count+=dfs(curr_v)
#     return count