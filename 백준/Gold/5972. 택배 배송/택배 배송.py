import sys
from heapq import heappush, heappop
si = sys.stdin.readline

n, m = map(int ,si().split())

g = [[] for _ in range(n + 1)]

class edge_t:
    def __init__(self, node, weight):
        self.node, self.weight = node, weight

    def __lt__(self, target):
        return self.weight < target.weight
    
    def __str__(self):
        return '<' + str(self.node) + ', ' + str(self.weight) + '>'
    
    def __iter__(self):
        return iter((self.node, self.weight))

for _ in range(m):
    a, b, weight = map(int, si().split())
    g[a].append(edge_t(b, weight))
    g[b].append(edge_t(a, weight))


def dijkstra(start : int = 1) -> int:
    dist = [500000005] * (n + 1)
    pq = []
    dist[start] = 0
    heappush(pq, edge_t(start, 0))

    while pq:
        node, weight = heappop(pq)

        if dist[node] < weight: continue

        for x in g[node]:
            if dist[x.node] <= dist[node] + x.weight: continue

            dist[x.node] = dist[node] + x.weight
            heappush(pq, edge_t(x.node, dist[x.node]))
    
    return -1 if dist[n] == 500000005 else dist[n]

print(dijkstra())