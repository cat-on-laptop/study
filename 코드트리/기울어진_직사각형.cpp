#include <iostream>

using namespace std;

int arr[25][25], n;
int dir[4][2] = {{-1, 1}, {-1, -1}, {1, -1}, {1, 1}};

inline int max(int x, int y){
    return x > y ? x : y;
}

bool inRange(int row, int col){
    return 0 <= row && row < n && 0 <= col && col < n;
}

int check(int row, int col, int x, int y){
    // row, col을 맨 밑점으로 하고 / 방향으로 x 만큼 \방향으로 y만큼 이동해서 총합을 리턴해 주는 함수
    
    int temp = 0;
    for(int d = 0; d < 4; ++d){
        if(d & 1) {
            for(int i = 0; i < y; ++i) {
                row = row + dir[d][0], col = col + dir[d][1];
                if(!inRange(row, col)) return 0;
                temp += arr[row][col];
            }
        }
        else {
            for(int i = 0; i < x; ++i) {
                row = row + dir[d][0], col = col + dir[d][1];
                if(!inRange(row, col)) return 0;
                temp += arr[row][col];
            }
        }
    }
    return temp;
}

int main(void){
    ios::sync_with_stdio(0), cin.tie(0);
    
    // input
    cin >> n;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            cin >> arr[i][j];

    int ans = 0;

    // 완전 탐색
    for(int row = 0; row < n; ++row) {
        for(int col = 0; col < n; ++col) {
            // row, col을 밑점으로 하는 마름모에 대하여 탐색
            // / 방향 \ 방향 이렇게 두번 가야하는데
            // 각 방향의 크기의 최대는 n - 1 까지만 됨
            for(int x = 1; x < n; ++x) {
                for(int y = 1; y < n; ++y) {
                    ans = max(ans, check(row, col, x, y));
                }
            }
        }
    }
    // output
    cout << ans << endl;

}