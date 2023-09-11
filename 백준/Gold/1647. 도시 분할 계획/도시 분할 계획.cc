#include <iostream>
#include <queue>

using std::cout;
using std::cin;
using std::ios;
using std::priority_queue;

int parent[100'005], rank[100'005], ans;
int v, e;

struct edge_t {
    int x, y, weight;

    edge_t(int _x, int _y, int _weight) : x(_x), y(_y), weight(_weight) {}

    bool operator< (const edge_t& x) const {
        return this->weight > x.weight;
    }
};

priority_queue<edge_t> pq;

int find(int x) {
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void Union(int x, int y) {
    int px = parent[x], py = parent[y];
    
    if(px == py) return;

    if(rank[px] < rank[py]) {
        parent[px] = py;
    }
    else if(rank[px] > rank[py]) {
        parent[py] = px;
    }
    else {
        parent[px] = py;
        ++rank[py];
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> v >> e;

    for(int i = 1; i <= v; ++i) parent[i] = i;

    for(int i = 0; i < e; ++i) {
        int x, y, w; cin >> x >> y >> w;
        pq.push(edge_t(x, y, w));
    }

	int cnt = 0;
    while(!pq.empty()) {
		if(cnt == v-2)break;
        edge_t curr = pq.top(); pq.pop();
        
        if(find(curr.x) == find(curr.y)) continue;
        // 같은 그룹이면 continue

        Union(curr.x, curr.y);
		++cnt;
        ans += curr.weight;
    }

    // output
    cout << ans;

    return 0;
}