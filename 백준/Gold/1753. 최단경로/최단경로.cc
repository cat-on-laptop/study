#include <iostream>
#include <queue>
#include <vector>
#define endl '\n'
#define inf 0x7fffffff
using namespace std;

int v, e, start;
struct edge_t{
    int v, w;
    bool operator< (const edge_t& x) const {
        return this->w > x.w;
    }
};

vector<edge_t> g[20005];
int dist[20005];
priority_queue<edge_t> pq;

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> v >> e >> start;
    for(int i = 1; i <= v; ++i) dist[i] = inf;
    dist[start] = 0;
    int a, b, c;
    for(int i = 0; i < e; ++i){
        cin >> a >> b >> c;
        g[a].push_back({b, c});
    }

    // dijkstra
    pq.push({start, dist[start]});
    while(!pq.empty()){
        edge_t curr = pq.top(); pq.pop();
        for(const edge_t &x : g[curr.v]){
            int cost = dist[curr.v] + x.w;
            if(cost < dist[x.v]){
                dist[x.v] = cost;
                pq.push({x.v, cost});
            }
        }
    }
    for(int i = 1; i <= v; ++i) (dist[i] == inf) ? cout << "INF" << endl : cout << dist[i] << endl;
    return 0;
}