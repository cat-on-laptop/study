#include <cstdio>
#include <queue>
#include <vector>
#define inf 0x7fffffff

using std::priority_queue;
using std::vector;

int n, m, dist[1005];

struct edge_t {
    int node, weight;

    edge_t(int _node, int _weight) : node(_node), weight(_weight) {}

    bool operator< (const edge_t & target) const {
        return this->weight > target.weight;
    }
};

vector<edge_t> arr[1005];

void dijkstra(int start) {
    for(int i = 1; i <= n; ++i) dist[i] = inf;
    dist[start] = 0;

    priority_queue<edge_t> pq;
    pq.push(edge_t(start, 0));

    while(!pq.empty()) {
        edge_t curr = pq.top(); pq.pop();
        
        if(dist[curr.node] < curr.weight) continue;

        for(const edge_t &x : arr[curr.node]) {
            if(dist[x.node] <= dist[curr.node] + x.weight) continue;

            dist[x.node] = dist[curr.node] + x.weight;
            pq.push(edge_t(x.node, dist[x.node]));
        }
    }
}

int main() {
    // input
    scanf("%d\n%d", &n, &m);
    
    for(int i = 0; i < m; ++i) {
        int x, y, w; scanf("%d %d %d", &x, &y,&w);
        arr[x].push_back(edge_t(y, w));
    }

    int start, end; scanf("%d\n%d", &start, &end);

    // dijkstra
    dijkstra(start);

    // output
    printf("%d", dist[end]);
    
    return 0;
}