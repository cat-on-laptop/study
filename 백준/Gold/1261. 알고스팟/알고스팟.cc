#include <iostream>
#include <deque>
#include <string>

using std::cin;
using std::cout;
using std::deque;
using std::string;

struct node_t {
    int row, col, cost;
    
    node_t(int r, int c, int ct) : row(r), col(c), cost(ct) {}
};

const int dir[4][2] = {-1,0, 1,0, 0,-1, 0,1};
int arr[100][100];
int visited[100][100];
int n, m;

int main() {
    std::ios::sync_with_stdio(0), cin.tie(0);
    cin >> m >> n;
    for(int i = 0; i < n; ++i) {
        string x; cin >> x;
        for(int j = 0; j < m; ++j)
            arr[i][j] = x[j] - '0';
    }

    // 0-1 bfs
    deque<node_t> dq; 
    dq.emplace_back(0, 0, 1);
    visited[0][0] = 1;

    while(!dq.empty()) {
        node_t curr = dq.front(); dq.pop_front();
        // cout << "curr " << curr.row <<", " <<curr.col << '\n';

        for(int d = 0; d < 4; ++d) {
            int nr = curr.row + dir[d][0], nc = curr.col + dir[d][1];
            if (0 > nr || nr >= n || 0 > nc || nc >= m || visited[nr][nc]) continue;

            if (arr[nr][nc]) {
                dq.emplace_back(nr, nc, curr.cost + 1);
                visited[nr][nc] = curr.cost + 1;
            }
            else {
                dq.emplace_front(nr, nc, curr.cost);
                visited[nr][nc] = curr.cost;
            }   
        }
    }
    cout << visited[n-1][m-1] - 1;
}