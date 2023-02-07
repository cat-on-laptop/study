#include <iostream>
#include <cstring>

using namespace std;

int arr[10][10], n, m, ans = 0x80000000;
int presum[10][10];

inline int max(int x, int y){
    return x > y ? x : y;
}

bool isOk(int row1, int col1, int row2, int col2, int row3, int col3, int row4, int col4){
    // 사각형이 겹치지 않으면 true 리턴하는 함수
    if(col2 < col3) return true;
    if(row2 < row3) return true;
    if(col4 < col1) return true;
    if(row4 < row1) return true;

    return false;
}

int sum(int a, int b, int c, int d){
    // (a, b)를 좌상단 (c, d)를 우하단으로 하는 사각형의 누적합을 리턴

    int x = presum[c][d];
    int y = b == 0 ? 0 : presum[c][b-1];
    int z = a == 0 ? 0 : presum[a-1][d];
    int w = (a == 0 || b == 0) ? 0 : presum[a-1][b-1];

    return x - y - z + w;
}

int main(void) {
    // input
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            cin >> arr[i][j];
 

    // 누적합을 구하기 위해 arr 배열 복사
    memcpy(presum, arr, sizeof(arr));

    // 가로
    for(int i = 0; i < n; ++i) 
        for(int j = 1; j < m; ++j)
            presum[i][j] += presum[i][j-1];

    // 세로
    for(int i = 1; i < n; ++i)
        for(int j = 0; j < m; ++j)
            presum[i][j] += presum[i-1][j];

    
    // 좌상단 우하단을 사각형의 모양으로 잡고
    // 두 사각형을 잡아 탐색

    for(int r1 = 0; r1 < n; ++r1)
        for(int c1 = 0; c1 < m; ++c1)
            for(int r2 = r1; r2 < n; ++r2)
                for(int c2 = c1; c2 < m; ++c2)
                    for(int r3 = 0; r3 < n; ++r3)
                        for(int c3 = 0; c3 < m; ++c3)
                            for(int r4 = r3; r4 < n; ++r4)
                                for(int c4 = c3; c4 < m; ++c4) 
                                    if(isOk(r1, c1, r2, c2, r3, c3, r4, c4)) 
                                        ans = max(ans, sum(r1, c1, r2, c2) + sum(r3, c3, r4, c4));
                                    

    // output        
    cout << ans << endl;                                
}