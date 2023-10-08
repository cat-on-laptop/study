#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
typedef long long ll;

int n, m, k;
vector<ll> tree;
vector<ll> arr;

void init(int node, int nodeLeft, int nodeRight) {
    if(nodeLeft == nodeRight) {
        tree[node] = arr[nodeLeft];
        return;
    }

    int mid = (nodeLeft + nodeRight) >> 1;
    init(node << 1, nodeLeft, mid);
    init((node << 1) + 1, mid + 1, nodeRight);

    tree[node] = tree[node << 1] + tree[(node << 1) + 1];
}

void update(int node, int nodeLeft, int nodeRight, int idx, ll val) {
    if (idx < nodeLeft || nodeRight < idx) return;

    if(nodeLeft == nodeRight) {
        tree[node] = val;
        return;
    }

    int mid = (nodeLeft + nodeRight) >> 1;
    update(node << 1, nodeLeft, mid, idx, val);
    update((node << 1) + 1, mid + 1, nodeRight, idx, val);

    tree[node] = tree[node << 1] + tree[(node << 1) + 1];
}

ll query(int node, int nodeLeft, int nodeRight, int queryLeft, int queryRight) {
    if (queryRight < nodeLeft || nodeRight < queryLeft) return 0;

    if(queryLeft <= nodeLeft && nodeRight <= queryRight) return tree[node];

    int mid = (nodeLeft + nodeRight) >> 1;

    ll left = query(node << 1, nodeLeft, mid, queryLeft, queryRight);
    ll right = query((node << 1) + 1, mid + 1, nodeRight, queryLeft, queryRight);

    return left + right;
}

int main() {
    std::ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> k;
    tree.resize(n << 2);
    arr.resize(n);

    for(int i = 0; i < n; ++i)
        cin >> arr[i];
    init(1, 0, n-1);

    int op;
    ll a, b;

    for(int i = 0; i < m + k; ++i) {
        cin >> op >> a >> b;
        if(op & 1) update(1,0,n-1,a-1,b); 
        else cout << query(1,0,n-1,a-1,b-1) << '\n';
    }   
    return 0;
}