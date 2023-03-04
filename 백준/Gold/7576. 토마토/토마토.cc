// 백준 7576
// idea : bfs를 통해 일수 파악

#include <iostream>
#include <queue>
#include <tuple>
#define endl '\n'

using namespace std;

queue<tuple<int, int, int>> q;

inline int max(int x, int y){
    return x > y ? x : y;
}

int arr[1005][1005], R, C;
bool visited[1005][1005];
int ans = -1;

bool inRange(int row, int col){
    return 0 <= row && row < R && 0 <= col && col < C;
}

int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // 상 하 좌 우

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> C >> R;
    for(int i = 0; i < R; ++i)
        for(int j = 0; j < C; ++j) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) {
                q.push(make_tuple(i, j, 0));    
                visited[i][j] = true;
            }
            else if(arr[i][j] == -1) visited[i][j] = true;
        }

    while(!q.empty()){
        int row, col, cnt;
        tie(row, col, cnt) = q.front();
        q.pop();
        

        for(int i = 0; i < 4; ++i){
            int nr = row + dir[i][0], nc = col + dir[i][1];
            if(inRange(nr, nc) && (!visited[nr][nc]) && arr[nr][nc] == 0){
                visited[nr][nc] = true;
                q.push(make_tuple(nr, nc, cnt + 1));
            }
        }
        ans = max(cnt, ans);
    }
    
    bool flag = true;

    for(int i = 0; i < R; ++i)
        for(int j = 0; j < C; ++j)
            flag = flag & visited[i][j];

    flag ? cout << ans : cout << -1;

}