#include <iostream>

using namespace std;

int arr[7][7], temp[7][7], temp1[7][7], temp2[7][7], temp3[7][7];
int check;

void rotate(int n, int matrix[7][7]) {
    // n by m 행렬을 시계방향으로 90도 회전시키는 함수
    // 결과값은 temp에 저장
    for(int row = 0; row < n; ++row) 
        for(int col = 0; col < n; ++col) 
            temp[col][n-1-row] = matrix[row][col];
}


int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int t; cin >> t;
    for(int tc = 1; tc <= t; ++tc) {
        int n; cin >> n;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                cin >> arr[i][j];
        
        // 90도 
        rotate(n, arr);
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                temp1[i][j] = temp[i][j];

        // 180도
        rotate(n, temp1);
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                temp2[i][j] = temp[i][j];
        
        // 270도
        rotate(n, temp2);
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                temp3[i][j] = temp[i][j];

        // output
        cout << '#' << tc << endl;
        for(int i = 0; i < n; ++i) {
            // 90
            for(int j = 0; j < n; ++j) 
                cout << temp1[i][j];
            
            cout << ' ';

            // 180
            for(int j = 0; j < n; ++j)
                cout << temp2[i][j];
            
            cout << ' ';

            // 270
            for(int j = 0; j < n; ++j)
                cout << temp3[i][j];
            cout << endl;
        }
    }

    return 0;
}