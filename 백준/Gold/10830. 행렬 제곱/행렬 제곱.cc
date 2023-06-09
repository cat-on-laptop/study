#include <iostream>
#define MOD 1000

using namespace std;

int n;
long long b;

int arr[5][5], temp[5][5], rst[5][5];

void mul(int x[5][5], int y[5][5]) {
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            temp[i][j] = 0;
            for(int k = 0; k < n; ++k) {
                temp[i][j] += x[i][k] * y[k][j];
            }
            temp[i][j] %= MOD;
        }
    }

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            x[i][j] = temp[i][j];
}

int main() {
    cin >> n >> b;
    for(int i = 0; i < n; ++i) {
        for(int j = 0;j < n; ++j) cin >> arr[i][j];
        rst[i][i] = 1; // 단위 행렬
    }

    for(b; b; b >>= 1) {
        if(b & 1) {
            mul(rst, arr);
        }
        mul(arr, arr);
    }

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) cout << rst[i][j] << ' ';
        cout << endl;
    }

}