#include <iostream>
#include <queue>
#include <cstring>

using std::cin;
using std::cout;
using std::queue;

const int dir[4][2] = {-1,0, 0,1, 1,0, 0,-1};
int n, offset = -1;
bool visited[100][100];
int arr[100][100];

inline int max(int x, int y) {
    return x > y ? x : y;
}

void bfs(int row, int col, int _offset) {
    queue<int> q; q.emplace(row); q.emplace(col);
    while(!q.empty()) {
        row = q.front(); q.pop();
        col = q.front(); q.pop();

        for(int d = 0; d < 4; ++d) {
            int nr = row + dir[d][0], nc = col + dir[d][1];

            if(0 > nr || nr >= n || 0 > nc || nc >= n || visited[nr][nc] || arr[nr][nc] <= _offset) continue;

            visited[nr][nc] = true;
            q.emplace(nr); q.emplace(nc);
        }
    }
}

int main() {
    // freopen("input.in", "r", stdin);
    std::ios::sync_with_stdio(), cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j) {
            cin >> arr[i][j];
            offset = max(offset, arr[i][j]);
        }

    int ans = -1;
    for(int i = 0; i < offset; ++i) {
        memset(visited, 0, sizeof(visited));
        int temp = 0;

        for(int row = 0; row < n; ++row)
            for(int col = 0; col < n; ++col) 
                if(arr[row][col] > i && !visited[row][col]) {
                    ++temp;
                    visited[row][col] = true;
                    bfs(row, col, i);
                }
        ans = max(ans, temp);       
    }
    
    cout << ans;
    
    return 0;
}