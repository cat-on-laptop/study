#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;

int n, m, k;
int arr[4'000'000], parent[4'000'005], parent2[4'000'004];

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
    int px = find(x), py = find(y);

    if (px == py) return;

    if (px > py) parent[py] = px;
    else parent[px] = py;
}

int upper_bound(int x) {
    // 2 3 4 5 7 8 9
    register int l = 0, r = m - 1, ans = m, mid, pmid;

    while (l <= r) {
        mid = l + ((r - l) >> 1);
        if (arr[mid] > x) {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    ans = find(ans);
    merge(ans, ans + 1);
    return ans;
}

void input() {
    cin >> n >> m >> k;

    for (int i = 0; i < m; ++i) cin >> arr[i];
}

void run() {
    for (int i = 1; i <= n; ++i) parent[i] = i;
    std::sort(arr, arr + m);
    int x;

    for (int i = 0; i < k; ++i) {
        cin >> x;
        cout << arr[upper_bound(x)] << '\n';
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    std::ios::sync_with_stdio(0), cin.tie(0);
    input();
    run();
}