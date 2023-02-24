#include <iostream>
#include <cstring>

using namespace std;

int arr[205][205], temp[205][205];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m;

inline bool inRange(int row, int col) {
    return 0 <= row && row < n && 0 <= col && col < n;
}

void boom(int row, int col) {
    memcpy(temp, arr, sizeof(arr));
    // row, col이 주어지면 주어진 자리에 적혀 있는 수만큼 십자로 폭탄이 터지는 함수
    if(!arr[row][col]) return;

    for(int i = 0; i < arr[row][col]; ++i) {
        for(int d = 0; d < 4; ++d) {
            int nr = row + i * dir[d][0], nc = col + i * dir[d][1];
            if(inRange(nr, nc)) temp[nr][nc] = 0;
        }
    }  
}

void drop() {
    memset(arr, 0, sizeof(arr));
    // temp에 있는 터지고 난 상태를 중력에 맞게 arr에 떨어뜨리는 함수

    for(int col = 0; col < n; ++col) {
        int idx = n - 1; // 밑에부터 채워야 하므로 arr의 높이 index를 관리하기 위한 변수

        for(int row = n - 1; row >= 0; --row) {
            if(temp[row][col]) {
                arr[idx--][col] = temp[row][col];
            }
        }
    }
}


int main() {
    // input
    cin >> n >> m;
    for(int i = 0; i < n; ++i) 
        for(int j = 0; j < n; ++j)
            cin >> arr[i][j];

    for(int q = 0 ; q < m; ++q) {
        int x; cin >> x; --x;
        for(int row = 0; row < n; ++row) {
            if(arr[row][x]) {
                boom(row, x);
                drop();
                break;
            }
        }
    }

    // output
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cout << arr[i][j];
            if(j < n - 1) cout << ' ';
        }
        if(i < n - 1) cout << endl;
    }
    return 0;
}