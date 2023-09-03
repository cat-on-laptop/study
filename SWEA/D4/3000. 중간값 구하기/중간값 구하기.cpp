#include <iostream>
#include <queue>
#include <functional>

using namespace std;

const int mod = 20171109;
priority_queue<int, vector<int>, greater<int>> big;
priority_queue<int, vector<int>, less<int>> small;
int ans, n;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int t; cin >> t;
    for(int tc = 1; tc <= t; ++tc) {
        big = priority_queue<int, vector<int>, greater<int>>();
        small = priority_queue<int, vector<int>, less<int>>();
        ans = 0;
        int val;
        // small이 하나 더 많게
        cin >> n >> val;

        small.push(val);

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < 2; ++j) {
                cin >> val;
                if(small.size() == big.size()) { // size가 같으면 small에 넣어줘야 함
                    big.push(val); small.push(big.top()); big.pop();
                }
                else {
                    small.push(val); big.push(small.top()); small.pop();
                }
            }
            ans += small.top();
            ans %= mod;
        }

        cout << "#" << tc << ' ' << ans << '\n';
    }
}