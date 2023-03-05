#include <cstdio>

const int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int arr[105][105], n, m, k, ans;
bool visited[105][105];

inline int max(int x, int y) {
    return x > y ? x : y;
}

int dfs(int row, int col) {
    int cnt = 1;

    for(int d = 0; d < 4; ++d) {
        int nr = row + dir[d][0], nc = col + dir[d][1];
        
        if(nr < 0 || nc < 0 || nr >= n ||nc >= m) continue;

        if(visited[nr][nc] || !arr[nr][nc]) continue;

        visited[nr][nc] = true;
        cnt += dfs(nr, nc);
    }

    return cnt;
}

int main() {
    // input
    // freopen("input.txt", "r", stdin);
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 0; i < k; ++i) {
        int row, col; scanf("%d %d", &row, &col); --row, --col;
        arr[row][col] = 1;
    }

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(arr[i][j]) {
                visited[i][j] = true;
                ans = max(ans, dfs(i,j));
            }
        }
    }

    // output
    printf("%d", ans);
    return 0;
}