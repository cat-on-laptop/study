#include <iostream>
#define MAX 100005

using std::cin;
using std::cout;

int n, k, arr[MAX], val;


void input() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        val = val > arr[i] ? val : arr[i];
    }
}

unsigned long long cnt(long long _x) {
    unsigned long long x = 0;

    for (int i = 0; i < n; ++i) {
        x += _x / arr[i];
    }
    return x;
}

unsigned long long psearch() {
    
    unsigned long long l = 1, r = (unsigned long long)val * k, ans = (unsigned long long)val * k, m; 
    //printf("l:%lld, r:%lld, ans:%lld\n", l, r, ans);
    while (l <= r) {
        m = l + ((r - l) >> 1);

        unsigned long long x = cnt(m);
        //printf("l:%lld, r:%lld, m:%lld, x:%d\n", l, r, m, x);
        if (x >= k) {
            ans = m;
            r = m - 1;
        }
        else l = m + 1;
    }

    return ans;
}

void process() {
    cout << psearch();
}

int main() {
    // freopen("input.txt", "r", stdin);
    input();
    process();
}