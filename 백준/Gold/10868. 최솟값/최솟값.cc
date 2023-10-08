#include <iostream>
#define MAX 0x7fffffff;

using std::cin;
using std::cout;

int arr[100'005], tree[400'000];
int n, m;

inline int min(int x, int y) {
	return x < y ? x : y;
}

void init(int node, int nodeLeft, int nodeRight) {
	if (nodeLeft == nodeRight) {
		tree[node] = arr[nodeLeft];
		return;
	}

	int mid = (nodeLeft + nodeRight) >> 1;
	init(node << 1, nodeLeft, mid);
	init((node << 1) + 1, mid + 1, nodeRight);

	tree[node] = min(tree[node << 1], tree[(node << 1) + 1]);
}

int query(int node, int nodeLeft, int nodeRight, int queryLeft, int queryRight) {
	if (queryRight < nodeLeft || nodeRight < queryLeft)
		return MAX;

	if (queryLeft <= nodeLeft && nodeRight <= queryRight)
		return tree[node];

	int mid = (nodeLeft + nodeRight) >> 1;

	int l = query(node << 1, nodeLeft, mid, queryLeft, queryRight);
	int r = query((node << 1)+1, mid + 1, nodeRight, queryLeft, queryRight);

	return min(l, r);
}

int main() {
	std::ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	init(1, 0, n - 1);

	int a, b;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		cout << query(1, 0, n - 1, a - 1, b - 1) << '\n';
	}
}