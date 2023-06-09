#include <iostream>
#include <queue>
#include <cstring>
#define MAX 1005

using namespace std;

const int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int arr[MAX][MAX], dist[MAX][MAX];
bool visited[MAX][MAX];
int ans = 0x7fffffff;
int n, m, t, cnt, gr, gc;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> t;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j) {
            cin >> arr[i][j];
            if(arr[i][j] == 2) {
                gr = i, gc = j;
            }
        }

    // without gram
    queue<int> q;
    visited[0][0] = true;
    int row, col;
    q.push(0), q.push(0);

    while(!q.empty()) {
        row = q.front(); q.pop();
        col = q.front(); q.pop();

        for(int d = 0; d < 4; ++d) {
            int nr = row + dir[d][0], nc = col + dir[d][1];

            if(0 > nr || n <= nr || 0 > nc || m <= nc || visited[nr][nc] || arr[nr][nc] == 1) continue;

            visited[nr][nc] = true; 
            dist[nr][nc] = dist[row][col] + 1;
            q.push(nr); q.push(nc);
        }
    }
    

    if(dist[n-1][m-1] > 0) ans = min(ans, dist[n-1][m-1]);


    // with gram
    if(visited[gr][gc]) {
       // init
        memset(dist, 0, sizeof(dist));
        memset(visited, 0, sizeof(visited));
        visited[0][0] = true;
        q.push(0), q.push(0);

        while(!q.empty()) {
            row = q.front(); q.pop();
            col = q.front(); q.pop();
            if(arr[row][col] == 2) break;
            
            for(int d = 0; d < 4; ++d) {
                int nr = row + dir[d][0], nc = col + dir[d][1];

                if(0 > nr || n <= nr || 0 > nc || m <= nc || visited[nr][nc] || arr[nr][nc] == 1) continue;

                visited[nr][nc] = true; 
                dist[nr][nc] = dist[row][col] + 1;
                q.push(nr); q.push(nc);
            }
        }
        queue<int> nq;
        nq.push(row); nq.push(col);
        memset(visited, 0, sizeof(visited));
        visited[row][col] = true;
        while(!nq.empty()) {
            row = nq.front(); nq.pop();
            col = nq.front(); nq.pop();

            for(int d = 0; d < 4; ++d) {
                int nr = row + dir[d][0], nc = col + dir[d][1];

                if(0 > nr || n <= nr || 0 > nc || m <= nc || visited[nr][nc]) continue;

                visited[nr][nc] = true; 
                dist[nr][nc] = dist[row][col] + 1;
                nq.push(nr); nq.push(nc);
            }
        
    }}

    if(dist[n-1][m-1] > 0) ans = min(ans, dist[n-1][m-1]);

    ans <= t ? cout << ans : cout << "Fail";

    return 0;
}