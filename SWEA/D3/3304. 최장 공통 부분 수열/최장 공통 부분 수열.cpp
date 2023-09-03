#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int dp[1005][1005]; // dp[i][j] := x[1 ~i]y[i~j]의 lcs길이
string x, y;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;

    for(int tc = 1; tc <= t; ++tc) {
        cin >> x >> y;
        for(int i = 1; i <= x.size(); ++i) {
            for(int j = 1; j <= y.size(); ++j) {
                if(x[i-1] == y[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        cout << "#" << tc << ' ' << dp[x.size()][y.size()] << '\n';
    }
}