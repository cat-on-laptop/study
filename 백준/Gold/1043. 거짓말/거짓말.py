import sys
si = sys.stdin.readline

n, m = map(int, si().split())
truth = list(map(int, si().split()))[1:]
parent = [i for i in range(n + 1)]

party = []
for _ in range(m):
    temp = list(map(int, si().split()))
    party.append(temp[1:])

def find(x:int)->int:
    if x == parent[x]: return x
    parent[x] = find(parent[x])
    return parent[x]

def merge(x:int, y:int)->None:
    px, py = find(x), find(y)
    if px == py: return

    parent[py] = px

for p in party:
    for x in p[1:]:
        merge(p[0], x)
ans = m

for p in party:
    flag = False
    for x in p:
        if flag: continue
        
        for t in truth:
            if find(t) == find(x): 
                flag = True
                break

    if flag: ans -= 1

print(ans)