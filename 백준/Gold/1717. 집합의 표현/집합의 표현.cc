#include <iostream>

using std::cin;
using std::cout;

int parent[100'000'5];

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
    int px = find(x), py = find(y);

    if(px == py) return;

    parent[px] = py;
}

int main() {
    std::ios::sync_with_stdio(0), cin.tie(0);

    int n, m;

    cin >> n >> m;

    for(int i = 0; i <= n; ++i) parent[i] = i;

    for(int i = 0; i < m; ++i) {
        int op, a, b;
        cin >> op >> a >> b;

        if(!op) merge(a, b);
        else {
            if(find(a) == find(b)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}