#include <iostream>

using namespace std;

int arr[25][25], n, m, ans = -1;

inline int max(int x, int y){
    return x > y ? x : y;
}

bool check(int a, int b, int c, int d){
    // 사각형 내부의 수가 모두 양수이면 true리턴
    for(int row = a; row <= c; ++row)
        for(int col = b; col <= d; ++col) 
            if(arr[row][col] <= 0) return false;
     
    return true;
}

int main(void) {
    // input
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            cin >> arr[i][j];

    // 완전 탐색
    for(int r1 = 0; r1 < n; ++r1)
        for(int c1 = 0; c1 < m; ++c1)
            for(int r2 = r1; r2 < n; ++r2)
                for(int c2 = c1; c2 < m; ++c2) 
                    if(check(r1, c1, r2, c2)) ans = max(ans, (r2 - r1 + 1) * (c2 - c1 + 1));

    // output
    cout << ans << endl;
}