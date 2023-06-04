#include <iostream>

using namespace std;

long long arr[1005][1005], imos[1005][1005];
int n, query;
int r1, c1, r2, c2, k, op;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    // input
    cin >> n >> query;
    for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) cin >> arr[i][j];

    // query
    for(int q = 0; q < query - 1; ++q) {
        cin >> op >> r1 >> c1 >> r2 >> c2 >> k;

        imos[r1][c1] += k;
        imos[r1][c2 + 1] -= k;
        imos[r2 + 1][c1] -= k;
        imos[r2 + 1][c2 + 1] += k;
    }


    for(int row = 0; row < n; ++row) { // 세로로 휩쓸기
        for(int col = 1; col < n; ++col) {
            imos[row][col] += imos[row][col - 1];
        }
    }

    for(int col = 0; col < n; ++col) { // 가로로 휩쓸기
        for(int row = 1; row < n; ++row) {
            imos[row][col] += imos[row - 1][col];
        }
    }

    for(int row = 0; row < n; ++row) { // imos와 배열 합
        for(int col = 0; col < n; ++col) {
            arr[row][col] += imos[row][col];
        }
    }

    long long ans = 0;
    cin >> query >> r1 >> c1 >> r2 >> c2;
    for(int row = r1; row <= r2; ++row) {
        for(int col = c1; col <= c2; ++col) {
            ans += arr[row][col];
        }
    }

    cout << ans;
}