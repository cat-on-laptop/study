#include <iostream>

using namespace std;

int arr[105][105], n;

void rotate(int r, int c, int m1, int m2, int m3, int m4, int dir){
    // 회전 시키는 함수

    if(dir == 0) {
        // 반시계 방향 회전
        int ds[4][2] = {{-1, 1}, {-1, -1}, {1, -1}, {1, 1}};
        
        // 1번 방향
        int temp = arr[r + m1*ds[0][0]][c + m1*ds[0][1]];
        for(int i = m1; i >= 1; --i) {
            arr[r + i*ds[0][0]][c + i*ds[0][1]] = arr[r + (i-1)*ds[0][0]][c + (i-1)*ds[0][1]];
        }
        r += m1*ds[0][0], c += m1*ds[0][1];
        
        // 2번 방향
        int temp2 = arr[r + m2 * ds[1][0]][c + m2 * ds[1][1]];
        for(int i = m2; i >= 2; --i) {
            arr[r + i*ds[1][0]][c + i*ds[1][1]] = arr[r + (i-1)*ds[1][0]][c +(i-1) * ds[1][1]];
        }
        arr[r + ds[1][0]][c + ds[1][1]] = temp;
        r += m2*ds[1][0], c += m2*ds[1][1];

        // 3번 방향
        int temp3 = arr[r + m3*ds[2][0]][c + m3*ds[2][1]];
        for(int i = m3; i >= 2; --i) {
            arr[r + i*ds[2][0]][c + i*ds[2][1]] = arr[r + (i-1)*ds[2][0]][c +(i-1) * ds[2][1]];
        }
        arr[r +ds[2][0]][c+ds[2][1]] = temp2;
        r += m3 * ds[2][0], c += m3 * ds[2][1];
        
        // 4번 방향
        for(int i = m4; i >= 2; --i) {
            arr[r + i*ds[3][0]][c + i*ds[3][1]] = arr[r + (i-1)*ds[3][0]][c +(i-1) * ds[3][1]];
        }
        arr[r+ds[3][0]][c+ds[3][1]] = temp3;
    }
    else {
        // 시계 방향 회전
        int ds[4][2] = {{-1, -1}, {-1, 1}, {1, 1}, {1, -1}};

        // 4번 방향
        int temp = arr[r + m4*ds[0][0]][c + m4*ds[0][1]];
        for(int i = m4; i >= 1; --i) {
            arr[r + i*ds[0][0]][c + i*ds[0][1]] = arr[r + (i-1)*ds[0][0]][c + (i-1)*ds[0][1]];
        }
        r += m4*ds[0][0], c += m4*ds[0][1];

        // 3번 방향
        int temp2 = arr[r + m3 * ds[1][0]][c + m3 * ds[1][1]];
        for(int i = m3; i >= 2; --i) {
            arr[r + i*ds[1][0]][c + i*ds[1][1]] = arr[r + (i-1)*ds[1][0]][c +(i-1) * ds[1][1]];
        }
        arr[r + ds[1][0]][c + ds[1][1]] = temp;
        r += m3*ds[1][0], c += m3*ds[1][1];

        // 2번 방향
        int temp3 = arr[r + m2*ds[2][0]][c + m2*ds[2][1]];
        for(int i = m2; i >= 2; --i) {
            arr[r + i*ds[2][0]][c + i*ds[2][1]] = arr[r + (i-1)*ds[2][0]][c +(i-1) * ds[2][1]];
        }
        arr[r +ds[2][0]][c+ds[2][1]] = temp2;
        r += m2 * ds[2][0], c += m2 * ds[2][1];

        // 1번 방향
        for(int i = m1; i >= 2; --i) {
            arr[r + i*ds[3][0]][c + i*ds[3][1]] = arr[r + (i-1)*ds[3][0]][c +(i-1) * ds[3][1]];
        }
        arr[r+ds[3][0]][c+ds[3][1]] = temp3;
    }
}

int main(void) {
    // input
    cin >> n;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            cin >> arr[i][j];

    int r, c, m1, m2, m3, m4, dir;
    cin >> r >> c >> m1 >> m2 >> m3 >> m4 >> dir;
    // dir 1 -> 시계방향 dir 0 반시계방향

    r -= 1, c -= 1;
    rotate(r, c, m1, m2, m3, m4, dir);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }

}