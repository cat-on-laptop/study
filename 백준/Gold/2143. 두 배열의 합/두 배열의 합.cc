#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

ll t;
vector<ll> a, b;
int n, m;

int main() {
    cin >> t;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        ll x; cin >> x; a.push_back(x);
    }
    cin >> m;
    for(int i = 0; i < m; ++i) {
        ll x; cin >> x; b.push_back(x);
    }

    for(int i = 0; i < n; ++i) {
        ll tot = a[i];
        for(int j = i+1; j < n; ++j) {
            tot += a[j];
            a.push_back(tot);
        }
    }

    for(int i = 0; i < m; ++i) {
        ll tot = b[i];
        for(int j = i+1; j < m; ++j) {
            tot += b[j];
            b.push_back(tot);
        }
    }

    sort(b.begin(), b.end());

    ll ans = 0;
    for(const ll &x : a) {
        ans += upper_bound(b.begin(), b.end(), t - x) - lower_bound(b.begin(), b.end(), t - x);
    }
    
    cout << ans << endl;

    return 0;
}