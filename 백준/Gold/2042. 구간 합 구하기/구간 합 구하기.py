import sys
si = sys.stdin.readline

n, m, k = map(int, si().split())

arr = []
for _ in range(n):
    arr.append(int(si()))
tree = [0] * (4 * n)

def init(node : int, nodeLeft : int, nodeRight : int) -> None:
    if nodeLeft == nodeRight:
        tree[node] = arr[nodeLeft]
        return

    mid = (nodeLeft + nodeRight) >> 1

    init(node << 1, nodeLeft, mid)
    init((node << 1) + 1, mid + 1, nodeRight)
    tree[node] = tree[node << 1] + tree[(node << 1) + 1]


def update(node : int, nodeLeft : int, nodeRight : int, idx : int, val : int) -> None:
    if idx < nodeLeft or nodeRight < idx:
        return

    if nodeLeft == nodeRight :
        tree[node] = val
        return

    mid = (nodeLeft + nodeRight) >> 1

    update(node << 1, nodeLeft, mid, idx, val)
    update((node << 1) + 1, mid + 1, nodeRight, idx, val)
    tree[node] = tree[node << 1] + tree[(node << 1) + 1]


def query(node : int, nodeLeft : int, nodeRight : int, queryLeft : int, queryRight : int) -> int:
    if queryRight < nodeLeft or nodeRight < queryLeft:
        return 0

    if queryLeft <= nodeLeft and nodeRight <= queryRight:
        return tree[node]

    mid = (nodeLeft + nodeRight) >> 1

    l, r = query(node << 1, nodeLeft, mid, queryLeft, queryRight), query((node << 1) + 1, mid + 1, nodeRight, queryLeft, queryRight)
    return l + r

init(1, 0, n-1)

# for x in tree[1:10]:
#     print(x, end = ' ')
# print()
'''
        15
    6       9
 3    3   4    5
1 2

'''

for _ in range(m + k):
    op, a, b = map(int, si().split())

    if op == 1:
        update(1, 0, n-1, a-1, b)
    else:
        print(query(1,0,n-1,a-1,b-1))