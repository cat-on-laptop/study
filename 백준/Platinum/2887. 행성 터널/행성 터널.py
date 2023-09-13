import sys
si = sys.stdin.readline

n = int(si())

xarr, yarr, zarr = [], [], []

for i in range(n):
    x, y, z = map(int, si().split())
    xarr.append((x, i))
    yarr.append((y, i))
    zarr.append((z, i))

xarr.sort()
yarr.sort()
zarr.sort()

edge = []

for curr in xarr, yarr, zarr:
    for i in range(1, n):
        w1, a = curr[i]
        w2, b = curr[i-1]
        edge.append((abs(w1 - w2), a, b))

edge.sort()

parent = [i for i in range(n + 1)]

def find_1303(x :int) -> int:
    if parent[x] == x:
        return x
    parent[x] = find_1303(parent[x])
    return parent[x]

def merge(x : int, y : int) -> None:
    px, py = find_1303(x), find_1303(y)

    if px == py: return

    parent[px] = py
    return

ans, cnt = 0, 0
for curr in edge:
    if cnt == n - 1: break
    w, a, b = curr

    if find_1303(a) == find_1303(b): continue

    ans += w
    merge(a, b)
    cnt += 1

print(ans)
