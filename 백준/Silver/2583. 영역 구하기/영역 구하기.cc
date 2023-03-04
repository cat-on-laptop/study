#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using std::queue;
using std::vector;
using std::sort;

const int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int arr[105][105], n, m, k;
bool visited[105][105];
vector<int> rst;

int bfs(int row, int col) {
    int cnt = 1; // 영역의 넓이

    queue<int> q; //row, col순서로 push
    visited[row][col] = true;
    q.push(row), q.push(col);

    while(!q.empty()) {
        int row = q.front(); q.pop();
        int col = q.front(); q.pop();

        for(int d = 0; d < 4; ++d) {
            int nr = row + dir[d][0], nc = col + dir[d][1];
            
            if(nr < 0 || nc < 0 || nr >= m || nc >= n) continue; // 범위 out

            if(arr[nr][nc] || visited[nr][nc]) continue; // 색칠되어 있거나 방문했다면 

            visited[nr][nc] = true;
            q.push(nr), q.push(nc);
            ++cnt;
        }
    }

    return cnt;
}

int main() {
    // input
    // freopen("input.txt", "r", stdin);
    scanf("%d %d %d", &m, &n, &k);
    for(int i = 0; i < k; ++i) {
        int r1, r2, c1, c2;
        scanf("%d %d %d %d", &c1, &r1, &c2, &r2);
        for(int i = r1; i < r2; ++i) {
            for(int j = c1; j < c2; ++j) {
                arr[i][j] = 1;
            }
        }
    }

    for(int row = 0; row < m; ++row) {
        for(int col = 0; col < n; ++col) {
            if(arr[row][col] || visited[row][col]) continue;
            // 색칠되어 있거나 방문한 자리라면 x

            rst.push_back(bfs(row, col));
        }
    }

    sort(rst.begin(), rst.end());
    printf("%d\n", (int)rst.size());
    for(const int &x : rst) printf("%d ", x);

    return 0;
}