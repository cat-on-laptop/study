#include <cstdio>
#define MAX 65536

int n, k;
int tree[300'000], arr[250'005];

void update(int node, int nodeLeft, int nodeRight, int idx, int diff) {
	if (idx < nodeLeft || nodeRight < idx) return;

	if (nodeLeft == nodeRight) {
		tree[node] += diff;
		return;
	}

	int mid = (nodeLeft + nodeRight) >> 1;
	update(node << 1, nodeLeft, mid, idx, diff);
	update((node << 1) + 1, mid + 1, nodeRight, idx, diff);

	tree[node] = tree[node << 1] + tree[(node << 1) + 1];
	return;
}

int query(int node, int nodeLeft, int nodeRight, int rank) {
	if (nodeLeft == nodeRight) return nodeLeft;

	int mid = (nodeLeft + nodeRight) >> 1;

	return rank <= tree[node << 1] ? query(node << 1, nodeLeft, mid, rank) : query((node << 1) + 1, mid + 1, nodeRight, rank - tree[node << 1]);
}

int main() {
	// freopen("input.in", "r", stdin);
	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; ++i)
		scanf("%d ", &arr[i]);

	const int m = (k + 1) >> 1;

	for (int i = 0; i < k - 1; ++i)
		update(1, 0, MAX, arr[i], +1);

	long long cnt = 0;
	// k - 1
	// i -> k - 1 => 0
	// i -> k => 1
	// i - t = k - 1
	// t = i - k + 1

	for (int i = k - 1; i < n; ++i) {
		update(1, 0, MAX, arr[i], +1);
		cnt += query(1, 0, MAX, m);
		update(1, 0, MAX, arr[i - k + 1], -1);
	}

	printf("%lld", cnt);
	int de = -1;
	return 0;
}