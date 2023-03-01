#include <cstdio>
#include <queue>
#include <vector>
#define inf 0x7fffffff

using std::priority_queue;
using std::vector;

int n, m, dist[1005], parent[1005], cnt = 1;

struct edge_t {
    int node, weight;

    edge_t(int _node, int _weight) : node(_node), weight(_weight) {}

    bool operator< (const edge_t & target) const {
        return this->weight > target.weight;
    }
};

vector<edge_t> arr[1005];
vector<int> path;

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
            parent[x.node] = curr.node;
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

    // parent
    path.push_back(end);
    int temp = parent[end];
    path.push_back(temp);
    while(temp != 0) {
        ++cnt;
        temp = parent[temp];
        path.push_back(temp);
    }
    path.pop_back();
    
    // output
    printf("%d\n", dist[end]);
    printf("%d\n", cnt);
    for(vector<int>::reverse_iterator iter = path.rbegin(); iter != path.rend(); ++iter) printf("%d ", *iter);

    return 0;
}