#include <cstdio>
#define MAX 105

inline int mymax(int x, int y) { return x > y ? x : y; }
inline int mymin(int x, int y) { return x < y ? x : y; }

int n, m;
int mem[MAX], cost[MAX];
int dp[MAX][MAX*MAX]; // dp[i][j] -> i번까지 app을 봤을때, 최소 j만큼의 코스트를 들여서 만들 수 있는 메모리


int main(){
    // input
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i) scanf("%d", mem + i);
    for(int i = 1; i <= n; ++i) scanf("%d", cost + i);

    // processing
    for(int i = 1; i <= n; ++i) {
        // 현재 app 종료 해서 메모리 확보할지 안할지 판단
        for(int j = 0; j < cost[i]; ++j) // i번째 app을 종료를 시키지 않았음 j가 cost[i] 보다 작으므로
            dp[i][j] = dp[i-1][j];
        // i번째 app을 종료 할 수 있음
        for(int j = cost[i]; j <= 10000; ++j) // j-cost[i]가 segfault!
            dp[i][j] = mymax(dp[i-1][j], dp[i-1][j-cost[i]] + mem[i]);  
        // app 종료하는 경우 -> dp[i-1][j- cost[i]] + mem[i] 
        // app 종료하지 않는 경우 -> dp[i-1][j]
    }

    int ans;
    for(int i = 10000 ; i >= 0; --i){
        if(dp[n][i] >= m) ans = i;
    }

    printf("%d\n", ans);
    return 0;
}