import sys
from heapq import heappush, heappop
si = sys.stdin.readline

n = int(si())
m = int(si())

arr = [[] for _ in range(n+1)]
dist = [float("inf")] * (n + 1)

class Edge:
    def __init__(self, node:int, weight:int):
        self.node = node
        self.weight = weight

    def __lt__(self, other):
        return self.weight < other.weight
    
    def __iter__(self):
        return iter((self.node, self.weight))

    def __str__(self):
        return f"<{self.node}, {self.weight}>"
    
for _ in range(m):
    x, y, w = map(int, si().split())
    arr[x].append(Edge(y,w))

start, end = map(int, si().split())
# dijkstra
pq = []
dist[start] = 0
heappush(pq, Edge(start, 0))

while pq:
    node, weight = heappop(pq)

    if dist[node] < weight: continue

    for n, e in arr[node]:
        if dist[n] <= dist[node] + e: continue

        dist[n] = dist[node] + e
        heappush(pq, Edge(n, dist[n]))

print(dist[end])
