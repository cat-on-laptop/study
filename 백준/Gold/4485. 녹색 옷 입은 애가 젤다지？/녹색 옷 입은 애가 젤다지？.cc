#include <cstdio>
#include <queue>

using std::priority_queue;

int n, cnt = 1;
int arr[130][130], dist[130][130];
const int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

struct edge_t {
    int row, col, weight;

    edge_t(int _row, int _col, int _weight) : row(_row), col(_col), weight(_weight) {}

    bool operator< (const edge_t& x) const {
        return this->weight > x.weight; // for min heap
    }
};

void dijkstra() {
    // initialize dist
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            dist[i][j] = 0x7fffffff;
    dist[0][0] = arr[0][0];

    priority_queue<edge_t> pq;
    pq.push(edge_t(0,0,dist[0][0]));

    while(!pq.empty()) {
        edge_t curr = pq.top(); pq.pop();

        if(dist[curr.row][curr.col] < curr.weight) continue;

        for(int d = 0; d < 4; ++d) {
            int nr = curr.row + dir[d][0], nc = curr.col + dir[d][1];

            if(nr < 0 || nr >= n || nc < 0 || nc >= n) continue;

            if(dist[nr][nc] <= dist[curr.row][curr.col] + arr[nr][nc]) continue;

            dist[nr][nc] = dist[curr.row][curr.col] + arr[nr][nc];
            pq.push(edge_t(nr, nc, dist[nr][nc]));
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    while(true) {
        scanf("%d", &n); 
        if (!n) break;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                scanf("%d", &arr[i][j]);
        
        dijkstra();        

        printf("Problem %d: %d\n", cnt++, dist[n-1][n-1]);
    }
    return 0;
}