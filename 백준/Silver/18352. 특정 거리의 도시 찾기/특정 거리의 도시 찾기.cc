#include <iostream>
#include <queue>
#include <vector>
#define inf 0x7fffffff;

using namespace std;

struct edge_t {
    int node, cost;

    edge_t(int _node, int _cost) : node(_node), cost(_cost) {};

    bool operator<(const edge_t& x) const {
        return this->cost > x.cost; // min-heap
    };
};

int dist[300005];
int n, m, k, x;
vector<edge_t> g[300005];

void dijkstra(int start) {
    priority_queue<edge_t> pq;
    pq.push(edge_t(start, 0));
    dist[start] = 0;

    while(!pq.empty()) {
        edge_t curr = pq.top(); pq.pop();
        for(const edge_t &x : g[curr.node]) {
            if(dist[x.node] > dist[curr.node] + x.cost) {
                dist[x.node] = dist[curr.node] + x.cost;
                pq.push(edge_t(x.node, dist[x.node]));
            }
        }
    }

}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> k >> x;
    for(int i = 1; i <= n; ++i) dist[i] = inf;

    for(int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        g[a].push_back(edge_t(b, 1));
    }

    dijkstra(x);

    bool flag = true;
    for(int i = 1; i <= n; ++i) {
        if(i == x) continue;
        if(dist[i] == k) {
            flag = false;
            cout << i << ' ';
        }
    }
    if(flag) cout << -1;
}