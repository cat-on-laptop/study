#include <iostream>
#define MAX 100005

using namespace std;

int arr[MAX];

inline int min(int x, int y) {
    return x > y ? y : x;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, s, l = 0, r = 0;
    cin >> n >> s;
    for(int i = 0; i < n; ++i) cin >> arr[i];

    int ans = n + 5, temp = arr[l];

    while(l <= r && r < n) {
        if(temp < s) temp += arr[++r];
        else {
            ans = min(ans, r - l + 1);
            temp -= arr[l++];
        }
    }
    
    ans == n + 5 ? cout << 0 : cout << ans;

}

