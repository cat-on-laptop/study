#include <iostream>
#include <algorithm>
 
using namespace std;
 
int a[25], b[25];
 
int main() {
    int t; cin >> t;
    for(int tc = 1; tc <= t; ++tc) {
        int n, m; cin >> n >> m;
 
        for(int i = 0; i < n; ++i) cin >> a[i];
        for(int j = 0; j < m; ++j) cin >> b[j];
 
        int ans = 0, temp;
 
        if(n < m) {
            for(int i = 0; i + n <= m; ++i) {
                temp = 0;
                for(int j = 0; j < n; ++j) {
                    temp += a[j] * b[i+j];
                }
                ans = max(ans, temp);
            }
        }
        else {
            for(int i = 0; i + m <= n; ++i) {
                temp = 0;
                for(int j = 0; j < m; ++j) {
                    temp += a[i+j] * b[j];
                }
                ans = max(ans, temp);
            }
        }
        cout << '#' << tc << ' ' << ans << endl;
    }
 
    return 0;
}