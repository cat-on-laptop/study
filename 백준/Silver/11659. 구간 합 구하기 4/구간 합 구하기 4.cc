#include <iostream>
#define MAX 100'000
#define endl '\n'
using namespace std;

int n, m;
int arr[MAX], dp[MAX];

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; ++i) cin >> arr[i];
    dp[0] = arr[0];
    for(int i = 1; i < n; ++i) dp[i] = dp[i-1] + arr[i];
    
    int i, j;
    for(int q = 0; q < m; ++q){
        cin >> i >> j; --i, --j;
        if (!i) cout << dp[j] << endl;
        else cout << dp[j] - dp[i-1] << endl;
    }


    return 0;
}