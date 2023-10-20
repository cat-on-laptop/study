#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

typedef long long ll;
using std::cin;
using std::cout;

int arr[100'000'5];
ll tree[400'000'5];

void init(int node, int nodeLeft, int nodeRight) {
	if (nodeLeft == nodeRight) {
		tree[node] = arr[nodeLeft];
		return;
	}

	int mid = (nodeLeft + nodeRight) >> 1;

	init(node << 1, nodeLeft, mid);
	init((node << 1) + 1, mid + 1, nodeRight);

	tree[node] = tree[node << 1] + tree[(node << 1) + 1];
}

void update(int node, int nodeLeft, int nodeRight, int idx, ll val) {
	if (idx < nodeLeft || nodeRight < idx)
		return;

	if (nodeLeft == nodeRight) {
		tree[node] = val;
		return;
	}

	int mid = (nodeLeft + nodeRight) >> 1;

	update(node << 1, nodeLeft, mid, idx, val);
	update((node << 1) + 1, mid + 1, nodeRight, idx, val);

	tree[node] = tree[node << 1] + tree[(node << 1) + 1];
}

ll get_value(int node, int nodeLeft, int nodeRight, int queryLeft, int queryRight) {
	if (queryRight < nodeLeft || nodeRight < queryLeft)
		return 0;

	if (queryLeft <= nodeLeft && nodeRight <= queryRight)
		return tree[node];

	int mid = (nodeLeft + nodeRight) >> 1;

	ll l = get_value(node << 1, nodeLeft, mid, queryLeft, queryRight);
	ll r = get_value((node << 1) + 1, mid + 1, nodeRight, queryLeft, queryRight);

	return l + r;
}

int main() {
	// freopen("input.txt", "r", stdin);
	std::ios::sync_with_stdio(0), cin.tie(0);

	int n, m; cin >> n >> m;

	//init(1, 0, n - 1);

	int op, a, b;
	for (int i = 0; i < m; ++i) {
		cin >> op >> a >> b;
		if (op) update(1, 0, n - 1, a - 1, b);
		else a > b ? cout << get_value(1, 0, n - 1, b - 1, a - 1) << '\n' : cout << get_value(1, 0, n - 1, a - 1, b - 1) << '\n';
	}
	//2 2
	//1 2 2
	//0 1 2



	return 0;
}