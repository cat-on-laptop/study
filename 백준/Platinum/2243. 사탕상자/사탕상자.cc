#include <cstdio>

int n;
int tree[4'000'005];

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

int query(int node, int nodeLeft, int nodeRight, int cnt) {
	if (nodeLeft == nodeRight) return nodeLeft;

	int mid = (nodeLeft + nodeRight) >> 1;

	return cnt <= tree[node << 1] ? query(node << 1, nodeLeft, mid, cnt) : query((node << 1) + 1, mid + 1, nodeRight, cnt - tree[node << 1]);
}

int main() {
	// freopen("input.in", "r", stdin);
	scanf("%d ", &n);
	int a, b, c;
	for (int i = 0; i < n; ++i) {
		scanf("%d %d ", &a, &b);
		if (a & 1) {
			int target = query(1, 0, 1'000'000, b);
			printf("%d\n", target);
			update(1, 0, 1'000'000, target, -1);
		}
		else {
			scanf("%d ", &c);
			update(1, 0, 1'000'000, b, c);
		}
	}
	
	return 0;
}