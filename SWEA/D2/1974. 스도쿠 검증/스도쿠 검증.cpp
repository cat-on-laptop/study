#include <iostream>

using namespace std;

int arr[9][9];
int check;

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int t; cin >> t;
    for(int tc = 1; tc <= t; ++tc) {
        for(int i = 0; i < 9; ++i) 
            for(int j = 0; j < 9; ++j) 
                cin >> arr[i][j];
        
        int ans = 1;

        // 행 단위로 검증
        for(int row = 0; row < 9; ++row) {
            check = 0;
            for(int col = 0; col < 9; ++col) {
                if(check & (1 << arr[row][col])) ans = 0;
                else check |= (1 << arr[row][col]);
            }
            for(int num = 1; num <= 9; ++num) 
                if(!(check & (1 << num))) ans = 0;
        }

        // cout << "after row " << ans << endl;

        // 열 단위로 검증
        for(int col = 0; col < 9; ++col) {
            check = 0;
            for(int row = 0; row < 9; ++row) {
                if(check & (1 << arr[row][col])) ans = 0;
                else check |= (1 << arr[row][col]);
            }
            for(int num = 1; num <= 9; ++num)
                if(!(check * (1 << num))) ans = 0;
        }

        // cout << "after col " << ans << endl;

        // 각 사각형 단위로 검증
        for(int row = 0; row < 3; ++row) {
            for(int col = 0; col < 3; ++col) {
                check = 0;
                for(int i = 0; i < 3; ++i) {
                    for(int j = 0; j < 3; ++j) {
                        if(check & (1 << arr[3*row+i][3*col+j])) ans = 0;
                        else check |= (1 << arr[3*row+i][3*col+j]);
                    }
                }
                for(int num = 1; num <= 9; ++num) 
                    if(!(check & (1 << num))) ans = 0;
            }
        }

        // cout << "after square " << ans << endl;

        cout << '#' << tc << ' ' << ans << endl;
    }

    return 0;
}