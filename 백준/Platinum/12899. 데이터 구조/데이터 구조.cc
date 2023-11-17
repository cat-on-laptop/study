#include <iostream>

using std::cin;
using std::cout;

long long tree[8'000'005];

void update(int node, int nodeLeft, int nodeRight, int idx, int diff) {
	if (idx < nodeLeft || nodeRight < idx) return;

	if (nodeLeft == nodeRight) {
		tree[node] += diff;
		return;
	}

	int mid = (nodeLeft + nodeRight) >> 1;

	update(node << 1, nodeLeft, mid, idx, diff);
	update(node << 1 | 1, mid + 1, nodeRight, idx, diff);

	tree[node] = tree[node << 1] + tree[node << 1 | 1];
}

int query(int node, int nodeLeft, int nodeRight, int k) {
	if (nodeLeft == nodeRight) return nodeLeft;

	int mid = (nodeLeft + nodeRight) >> 1;
	return tree[node << 1] >= k ? query(node << 1, nodeLeft, mid, k)
		: query(node << 1 | 1, mid + 1, nodeRight, k - tree[node << 1]);
}

int main() {
	// freopen("input.in", "r", stdin);
	std::ios::sync_with_stdio(false); 
	cin.tie(nullptr);

	int n, t, x;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> t >> x;
		if (t & 1) update(1, 0, 2'000'000, x, 1);
		else {
			x = query(1, 0, 2'000'000, x);
			cout << x << '\n';
			update(1, 0, 2'000'000, x, -1);
		}
	}
	return 0;
}