#include <iostream>
#define endl '\n'

using std::cin;
using std::cout;

int main () {
    std::ios::sync_with_stdio(0), cin.tie(0);
    int T; cin >> T;
    int n, m;
    for(int tc = 1; tc <= T; ++tc) {
        cin >> n >> m;

        bool flag = true;

        for(int i = 0; i < n; ++i) {
            flag &= (m & 1);
            m >>= 1;
        }
        cout << "#" << tc << ' ' ;
        flag ? cout << "ON" << endl : cout << "OFF" << endl;
    }
}