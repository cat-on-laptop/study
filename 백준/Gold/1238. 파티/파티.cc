#include <iostream>
#include <queue>
#include <vector>
#define inf 0x7fffffff

using namespace std;

inline int max(int x, int y) {
    return x > y ? x : y;
}

struct edge_t {
    int node, weight;

    edge_t(int _node, int _weight) : node(_node), weight(_weight) {}

    bool operator<(const edge_t &x) const {
        return this->weight > x.weight;
    }
};

vector<edge_t> g[2][1005]; // 0 -> 정방향, 1 -> 역방향
// 역방향으로 도착지에서 다잌 돌리면 모든 출발지에서 목적지로 도착 가능한 최단 거리가 구해짐

int dist[2][1005];
int n, m, t, ans;

void dijkstra(int dir) {
    for(int i = 0; i < 1005; ++i) dist[dir][i] = inf;
    dist[dir][t] = 0;
    priority_queue<edge_t> pq;
    pq.push(edge_t(t, dist[dir][t]));

    while(!pq.empty()) {
        edge_t curr = pq.top(); pq.pop();

        if(dist[dir][curr.node] < curr.weight) continue;

        for(const edge_t &x : g[dir][curr.node]) {
            if(dist[dir][x.node] <= dist[dir][curr.node] + x.weight) continue;

            dist[dir][x.node] = dist[dir][curr.node] + x.weight;
            pq.push(edge_t(x.node, dist[dir][x.node]));
        }
    }
}

int main() {
    cin >> n >> m >> t;

    for(int i = 0; i < m; ++i) {
        int a, b, c; cin >> a >> b >> c;
        // 정방향
        g[0][a].push_back(edge_t(b, c));
        g[1][b].push_back(edge_t(a, c));
    }

    dijkstra(0); // 정방향
    dijkstra(1); // 역방향

    for(int i = 1; i <= n; ++i) {
        if(dist[0][i] == inf || dist[1][i] == inf) continue;

        int temp = dist[0][i] + dist[1][i];
        ans = max(ans, temp);
    }

    cout << ans << endl;

    return 0;
}