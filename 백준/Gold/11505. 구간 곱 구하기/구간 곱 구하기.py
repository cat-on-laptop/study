import sys
si = sys.stdin.readline

n, m, k = map(int, si().split())
arr = []
tree = [0] * (n << 2)

for _ in range(n):
    arr.append(int(si()))

def init(node : int, nodeLeft : int, nodeRight : int) -> None:
    if nodeLeft == nodeRight:
        tree[node] = arr[nodeLeft]
        return

    mid = (nodeLeft + nodeRight) >> 1
    init(node << 1, nodeLeft, mid)
    init((node << 1) + 1, mid + 1, nodeRight)

    tree[node] = (tree[node << 1] * tree[(node << 1) + 1]) % 1_000_000_007

def update(node : int, nodeLeft : int, nodeRight : int, idx : int, val : int) -> None:
    if idx < nodeLeft or nodeRight < idx:
        return

    if nodeLeft == nodeRight:
        tree[node] = val
        return

    mid = (nodeLeft + nodeRight) >> 1
    update(node << 1, nodeLeft, mid, idx, val)
    update((node << 1) + 1, mid + 1, nodeRight, idx, val)

    tree[node] = (tree[node << 1] * tree[(node << 1) + 1]) % 1_000_000_007


def get_val(node : int, nodeLeft : int, nodeRight : int, queryLeft : int, queryRight : int) -> int:
    if queryRight < nodeLeft or nodeRight < queryLeft:
        return 1

    if queryLeft <= nodeLeft and nodeRight <= queryRight:
        return tree[node]

    mid = (nodeLeft + nodeRight) >> 1

    l, r = get_val(node << 1, nodeLeft, mid, queryLeft, queryRight), get_val((node << 1) + 1, mid +1, nodeRight, queryLeft, queryRight)

    return (l*r) % 1_000_000_007

init(1, 0, n-1)

for _ in range(m + k):
    a, b, c = map(int, si().split())

    if a & 1 :
        update(1,0,n-1,b-1,c)
    else:
        print(get_val(1,0,n-1,b-1,c-1))
