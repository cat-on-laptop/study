#include <iostream>
#define endl '\n'

using std::cin;
using std::cout;

int main () {
    std::ios::sync_with_stdio(0), cin.tie(0);
    int T; cin >> T;

    for(int tc = 1; tc <= T; ++tc) {
        long long n; cin >> n;
        int ans = 0, cnt = 0;
        int flag = 0b1111111111;
        

        while((flag & cnt) != flag) {
            ++ans;
            long long temp = ans * n;
            // cout << temp << endl;
            while(temp) {
                cnt |= (1 << (temp % 10));
                temp /= 10;
            } 
        }
        
        cout << "#" << tc << ' ' << ans * n << endl;
    }
}