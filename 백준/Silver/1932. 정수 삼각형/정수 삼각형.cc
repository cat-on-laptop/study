#include <iostream>
#include <algorithm>
#define MAX 501
using namespace std;

int arr[MAX][MAX];
int dp[MAX][MAX];

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int n; cin >> n;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= i; ++j){
            cin >> arr[i][j];
        }
    }

    dp[1][1] = arr[1][1];
    for(int i = 2; i <= n; ++i) {
        dp[i][1] = arr[i][1] + dp[i-1][1];
        dp[i][i] = arr[i][i] + dp[i-1][i-1];
    }

    for(int i = 2; i <= n; ++i){
        for(int j = 2; j < i; ++j){
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + arr[i][j];
        }
    }

    int max = -1;
    for(int i = 1; i <=n; ++i) max = max > dp[n][i] ? max : dp[n][i];

    cout << max << endl;

    return 0;
}