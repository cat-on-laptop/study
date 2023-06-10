#include <iostream>
#include <algorithm>

using namespace std;

int arr[100005], n , m;
int l, r, ans = 0x7fffffff;

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; ++i) cin >> arr[i];
    sort(arr, arr + n);

    while(l <= r && r < n) {
        if(arr[r] - arr[l] >= m) {
            ans = min(ans, arr[r] - arr[l]);
            ++l;
        }
        else {
            ++r;
        }
    }

    cout << ans << endl;
}