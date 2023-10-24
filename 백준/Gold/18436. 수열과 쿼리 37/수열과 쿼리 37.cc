#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int arr[100005], tree[400005];

void init(int node, int nodeLeft, int nodeRight) {
	if (nodeLeft == nodeRight) {
		tree[node] = arr[nodeLeft] & 1;
		return;
	}

	int mid = (nodeLeft + nodeRight) >> 1;

	init(node << 1, nodeLeft, mid);
	init((node << 1) + 1, mid + 1, nodeRight);

	tree[node] = tree[node << 1] + tree[(node << 1) + 1];
}

void update(int node, int nodeLeft, int nodeRight, int idx, int val) {
	if (idx < nodeLeft || nodeRight < idx) return;

	if (nodeLeft == nodeRight) {
		tree[node] = val & 1;
		return;
	}

	int mid = (nodeLeft + nodeRight) >> 1;

	update(node << 1, nodeLeft, mid, idx, val);
	update((node << 1) + 1, mid + 1, nodeRight, idx, val);

	tree[node] = tree[node << 1] + tree[(node << 1) + 1];
}

int query(int node, int nodeLeft, int nodeRight, int queryLeft, int queryRight) {
	if (queryRight < nodeLeft || nodeRight < queryLeft)
		return 0;

	if (queryLeft <= nodeLeft && nodeRight <= queryRight)
		return tree[node];

	int mid = (nodeLeft + nodeRight) >> 1;

	int l = query(node << 1, nodeLeft, mid, queryLeft, queryRight);
	int r = query((node << 1) + 1, mid + 1, nodeRight, queryLeft, queryRight);

	return l + r;
}

int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &arr[i]);

	init(1, 0, n - 1);

	int q; scanf("%d", &q);
	int x, y, z;
	for (int i = 0; i < q; ++i) {
		scanf("%d %d %d", &x, &y, &z);
		if (x == 1) {
			update(1, 0, n - 1, y - 1, z);
		}
		else if (x == 2) {
			int temp = query(1, 0, n - 1, y - 1, z - 1);
			printf("%d\n", z - y + 1 - temp);
		}
		else
			printf("%d\n", query(1, 0, n - 1, y - 1, z - 1));
	}
}