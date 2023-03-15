#include <cstdio>
#include <cstring>

const int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int arr[55][55], temp[55][55];
int r, c, t, aR1, aR2;

void printarr() {
    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j)
            printf("%d ", arr[i][j]);
        puts("");
    }
}

void printtemp() {
    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j)
            printf("%d ", temp[i][j]);
        puts("");
    }
}

void dust() {
    // 먼지의 확산
    memset(temp, 0, sizeof(temp));

    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j) {

            if(arr[i][j] > 0) {
                int m = arr[i][j] / 5;
                for(int d = 0; d < 4; ++d) {
                    int nr = i + dir[d][0], nc = j + dir[d][1];
                    if(0 > nr || 0 > nc || nr >= r || nc >= c) continue;

                    if(arr[nr][nc] == -1) continue;
                    
                    temp[nr][nc] += m;
                    arr[i][j] -= m;
                }
                temp[i][j] += arr[i][j];
            }
            else if(arr[i][j] == -1) temp[i][j] = -1;
        }
    }
    memcpy(arr, temp, sizeof(arr));
}

void airClean() {
    // 위의 공청기 회전
    int row = aR1;

    // 위의 공청기중 맨 아래줄
    int temp = arr[row][c-1];
    for(int i = c - 1; i > 1; --i) {
        arr[row][i] = arr[row][i-1];
    }
    arr[row][1] = 0;

    // 위의 공청기중 맨 오른쪽 줄 위로
    int temp1 = arr[0][c-1];
    for(int i = 0; i < row; ++i) {
        arr[i][c-1] = arr[i+1][c-1];
    }
    arr[row-1][c-1] = temp;
    
    // 위의 공청기중 맨 윗줄을 왼쪽으로
    temp = arr[0][0];
    for(int i = 0; i < c-2; ++i) {
        arr[0][i] = arr[0][i+1];
    }
    arr[0][c-2] = temp1;
    
    // 위의 공청기중 맨 왼쪽 줄을 아래로
    for(int i = row - 1; i > 1; --i) {
        arr[i][0] = arr[i-1][0];
    }
    arr[1][0] = temp;


    // 아래
    row = aR2;

    // 아래의 맨 윗줄을 오른쪽으로
    temp = arr[row][c-1];
    for(int i = c - 1; i > 1; --i) {
        arr[row][i] = arr[row][i-1];
    }
    arr[row][1] = 0;

    // 아래의 맨 오른쪽을 아래로
    temp1 = arr[r-1][c-1];
    for(int i = r - 1; i > row + 1; --i) {
        arr[i][c-1] = arr[i-1][c-1];
    }
    arr[row+1][c-1] = temp;

    // 아래의 맨 아래를 왼쪽으로
    temp = arr[r-1][0];
    for(int i = 0; i < c-2; ++i) {
        arr[r-1][i] = arr[r-1][i+1];
    }
    arr[r-1][c-2] = temp1;

    // 아래의 맨 왼쪽을 위로
    for(int i = row + 1; i < r-2; ++i) {
        arr[i][0] = arr[i+1][0];
    }
    arr[r-2][0] = temp;
}

int main() {
    // input
    // freopen("input.txt", "r", stdin);
    scanf("%d %d %d", &r, &c, &t);

    for(int i = 0; i < r; ++i) 
        for(int j = 0; j < c; ++j) {
            scanf("%d", &arr[i][j]);
            if(arr[i][j] == -1) {
                if(!aR1) aR1 = i;
                else aR2 = i;
            } 
        }

    
    while(t--) {
        dust(); // 먼지의 확산
        airClean(); // 공청기 가동
    }
    
    int tot = 0;
    for(int i = 0; i < r; ++i) 
        for(int j = 0; j < c; ++j) 
            if(arr[i][j] > 0) tot += arr[i][j];
    

    // output
    printf("%d", tot);
}