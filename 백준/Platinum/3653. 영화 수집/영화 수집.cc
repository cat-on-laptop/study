#include <iostream>

using std::cin;
using std::cout;

int DAT[100'005];

class Segtree {
    long long tree[1 << 20];
    int offset;

public:
    void init(int n, int m) {
        for (offset = 1; offset < (n + m) << 1; offset <<= 1);
        for (int i = 0; i < offset << 1; ++i)
            tree[i] = 0;
        // leaf
        for (int i = offset; i < offset + n; ++i)
            tree[i] = 1;

        // interval 
        for (int i = offset - 1; i > 0; --i)
            tree[i] = tree[i << 1] + tree[i << 1 | 1];
    }

    void update(int idx, int val) {
        idx += offset;
        tree[idx] += val;
        idx >>= 1;

        while (idx) {
            tree[idx] = tree[idx << 1] + tree[idx << 1 | 1];
            idx >>= 1;
        }
    }

    long long query(int a, int b) {
        a += offset; b += offset;
        long long ret = 0;

        while (a <= b) {
            if (a & 1) ret += tree[a];
            if (!(b & 1))ret += tree[b];

            a = (a + 1) >> 1;
            b = (b - 1) >> 1;
        }
        return ret;
    }
}seg;

int main() {
    // freopen("input.in", "r", stdin);
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t, m, x;

    cin >> t;

    for (int i = 0; i < t; ++i) {
        cin >> n >> m;
        seg.init(n, m);
        for (int i = 1; i <= n; ++i)
            DAT[i] = n - i;

        int e = n - 1;
        for (int j = 0; j < m; ++j) {
            cin >> x;
            cout << seg.query(DAT[x] + 1, e) << ' ';
            seg.update(DAT[x], -1);
            seg.update(++e, 1);
            DAT[x] = e;
        }
        cout << '\n';
    }

    return 0;
}