#include <iostream>

using namespace std;

int dp[10005], arr[105];
int n, m;

int main(int argc, char **argv) {
    // input
    cin >> n >> m;
    for(int i = 0; i < n; ++i) cin >> arr[i];

    // initialize dp table
    for(int i = 1; i <= m; ++i) dp[i] = 10005;

    for(int i = 0; i < n; ++i) {
        for(int j = m; j > 0; --j) {
            if(arr[i] <= j) {
                dp[j] = min(dp[j - arr[i]] + 1, dp[j]);
            }
        }
    }
 
    // out put
    dp[m] == 10005 ? cout << -1 << endl : cout << dp[m] << endl;

    return 0;
}