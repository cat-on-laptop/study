#include <iostream>

using namespace std;

int n, m;
int dp[10005], coin[105];

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; ++i) cin >> coin[i];
    // dp의 초기값은 overflow를 대비하여 나올 수 있는 최대 값을 넘는 10005로 초기화
    for(int i = 1; i <= m; ++i) dp[i] = 10005;

    for(int i = 1; i <= m; ++i) {
        for(int j = 0; j < n; ++j) {
            if(coin[j] <= i) {
                dp[i] = min(dp[i], dp[i-coin[j]] + 1);     
            }
        }
    }


    dp[m] != 10005 ? cout << dp[m] : cout << -1;
}