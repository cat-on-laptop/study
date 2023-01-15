// 백준 1987
// 백트레킹
// 돌아다니는 과정에서 필요한 정보
// 1. 현재위치
// 2. 밟았던 알파벳
// 3. 이때까지 이동 길이

#include <iostream>
#define MAX 25
#define endl '\n'
using namespace std;

int r, c, ans = 0x80000000; // row, col, 정답 변수
int d[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // 상 하 좌 우
char arr[MAX][MAX];
bool visited[26]; // 사용한 알파벳 기록

inline int max(int x, int y){
    return x > y ? x : y;
}

inline bool check(int row, int col){
    return 0 <= row && row < r && 0 <= col && col < c;
}

void backtracking(int row, int col, int dist){
    // 현재 위치 row, col 과 이동거리 dist를 가지고 남은 모든 경우를 탐색해 주는 함수
    
    ans = max(dist, ans); // 정답 갱신
    
    visited[arr[row][col] - 'A'] = true; // 밟았다.
    
    for(int i = 0; i < 4; ++i){
        int nr = row + d[i][0], nc = col + d[i][1];
        if(check(nr, nc) && !visited[arr[nr][nc] - 'A']){
            backtracking(nr, nc, dist + 1);
        }
    }

    visited[arr[row][col] - 'A'] = false; // 다시 리셋

}


int main(void){
    ios::sync_with_stdio(0), cin.tie(0);
    
    // input
    cin >> r >> c;
    for(int i = 0; i < r; ++i){
        for(int j = 0; j < c; ++j)
            cin >> arr[i][j];
    }

    // do
    backtracking(0, 0, 1); // 첫 판도 밟은 거리로 치니
    cout << ans << endl;

    return 0;
}