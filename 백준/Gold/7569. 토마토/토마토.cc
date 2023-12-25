/*
    1인 지점에 대해서 6방향으로 확산
    확산된 지점은 q에 넣어서 계속 확산되도록!
*/

#include <iostream>
#include <queue>

using std::cin;
using std::cout;
using std::queue;

struct node_t {
    int row, col, height;

    node_t(int r, int c, int h) : row(r), col(c), height(h) {}
};

const int dir[6][3] = {-1,0,0, 0,1,0, 1,0,0, 0,-1,0, 0,0,1, 0,0,-1}; // row, col, height
int visited[100][100][100], arr[100][100][100];
int R, C, H;
queue<node_t> q;

inline int max(int x, int y) {
    return x > y ? x : y;
}

void spread(int row, int col, int height) {
    for(int d = 0; d < 6; ++d) {
        int nr = row + dir[d][0], nc = col + dir[d][1], nh = height + dir[d][2];

        if(0 > nr || nr >= R || 0 > nc || nc >= C || 0 > nh || nh >= H) continue;
        if(visited[nh][nr][nc] || arr[nh][nr][nc] < 0) continue;

        visited[nh][nr][nc] = visited[height][row][col] + 1;
        arr[nh][nr][nc] = 1;
        q.emplace(nr, nc, nh);
    }
}

int main() {
    // freopen("input.in", "r", stdin);
    std::ios::sync_with_stdio(0), cin.tie(0);

    // input
    cin >> C >> R >> H;
    for(int h = 0; h < H; ++h)
        for(int r = 0; r < R; ++r)
            for(int c = 0; c < C; ++c) {
                cin >> arr[h][r][c];
                if (arr[h][r][c] == 1) {
                    visited[h][r][c] = 1;
                    q.emplace(r,c,h);
                }
            }

    while(!q.empty()) {
        node_t curr = q.front(); q.pop();
        spread(curr.row, curr.col, curr.height);
    }

    bool rst = true;
    int ans = -1;
    
    for(int h = 0; h < H; ++h)
        for(int r = 0; r < R; ++r)
            for(int c = 0; c < C; ++c) {
                if(arr[h][r][c] == 0) {
                    rst = false; 
                    break;
                }
                ans = max(visited[h][r][c], ans);
            }
    cout << (rst ? ans - 1 : -1);
    return 0;
}