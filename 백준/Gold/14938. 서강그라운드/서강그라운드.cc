#include <iostream>
#include <vector>
#include <queue>

using namespace std;

inline int max(int x, int y) {
    return x > y ? x : y;
}

struct edge_t{
    int vertex, weight;

    edge_t(int x, int y) : vertex(x), weight(y) {}

    bool operator<(const edge_t &x) const {
        // min-heap 구현을 위해 
        return this->weight > x.weight;
    }
};

vector<edge_t> graph[105];
int items[105];
int n, m, r, ans;

int dijkstra(int start) {
    priority_queue<edge_t> pq;
    vector<int> dist(n + 1, 10000000);

    dist[start] = 0;
    pq.push(edge_t(start, dist[start]));

    while(!pq.empty()) {
        edge_t curr = pq.top(); pq.pop();
        int v = curr.vertex, w = curr.weight;

        // dist[v]가 w보다 큰 경우는 skip
        if(dist[v] < w) continue;

        for(const edge_t &x : graph[v]) {
            // 현재 current vertex의 거리 + x의 가중치가 x의 dist 이상이면 skip
            if(dist[x.vertex] <= x.weight + dist[v]) continue;

            dist[x.vertex] = x.weight + dist[v];
            pq.push(edge_t(x.vertex, dist[x.vertex]));
        }
    }

    // 거리가 m이하면 값 더해주기
    int tot = 0;
    for(int i = 1; i <= n; ++i) if(dist[i] <= m) tot += items[i];

    return tot;    
}

int main() {
    // ios::sync_with_stdio(0), cin.tie(0);
    // input
    cin >> n >> m >> r;
    // n 섬의 개수, m 수색 범위, r edge의 개수

    for(int i = 1; i <= n; ++i) cin >> items[i];
    // i번 섬에 있는 item의 수

    for(int i = 0; i < r; ++i) {
        int x, y, w; cin >> x >> y >> w;
        // 양방향 그래프 이므로 x, y를 vertex, w를 weight로하는 edge를 추가
        graph[x].push_back(edge_t(y, w));
        graph[y].push_back(edge_t(x, w));
    }

    // n개의 시작점에 대해 모두 다잌스트라 돌려보기
    for(int i = 1; i <= n; ++i) ans = max(ans, dijkstra(i));

    // output
    cout << ans;

    return 0;
}
