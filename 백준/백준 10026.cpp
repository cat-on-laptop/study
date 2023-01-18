// 백준 10026

#include <iostream>
#include <queue>
#include <cstring>
#define MAX 105
#define endl '\n'

using namespace std;

char arr[MAX][MAX];
bool visited[MAX][MAX];
int n, cnt1, cnt2;

int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool inRange(int row, int col){
    return 0 <= row && row < n && 0 <= col && col < n;
}

bool normal(int row, int col, int nr, int nc){
    return arr[row][col] == arr[nr][nc];
}

bool abnormal(int row, int col, int nr, int nc){
    if(arr[row][col] == 'R' || arr[row][col] == 'G'){
        return arr[nr][nc] == 'R' || arr[nr][nc] == 'G';
    }
    else return arr[row][col] == arr[nr][nc];
}

void bfs(int row, int col){
    queue<pair<int, int>> q;
    q.push({row, col});

    while(!q.empty()){
        pair<int, int> curr = q.front(); q.pop();
        for(int i = 0; i < 4; ++i){
            int nr = curr.first + dir[i][0], nc = curr.second + dir[i][1];
            if(inRange(nr, nc) && !visited[nr][nc] && normal(row, col, nr, nc)){
                visited[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    }
}

void bfs2(int row, int col){
    queue<pair<int, int>> q;
    q.push({row, col});

    while(!q.empty()){
        pair<int, int> curr = q.front(); q.pop();
        for(int i = 0; i < 4; ++i){
            int nr = curr.first + dir[i][0], nc = curr.second + dir[i][1];
            if(inRange(nr, nc) && !visited[nr][nc] && abnormal(row, col, nr, nc)){
                visited[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    }
}

int main(void){
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    
    // input
    cin >> n;
    for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) cin >> arr[i][j];

    // 정상인 탐색
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(!visited[i][j]){
                visited[i][j] = true;
                ++cnt1;
                bfs(i, j);
            }
        }
    }

    // visited 초기화
    memset(visited, false, sizeof(visited));

    // 색맹 탐색
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(!visited[i][j]){
                visited[i][j] = true;
                ++cnt2;
                bfs2(i, j);
            }
        }
    }

    cout << cnt1 << endl << cnt2;
}