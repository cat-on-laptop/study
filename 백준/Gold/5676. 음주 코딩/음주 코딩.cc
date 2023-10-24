#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

inline int convert(int x) {
	if (x > 0) return 1;
	else if (x < 0) return -1;
	else return 0;
}

int arr[100'005], tree[400'005];

void init(int node, int nodeLeft, int nodeRight) {
	if (nodeLeft == nodeRight) {
		tree[node] = convert(arr[nodeRight]);
		return;
	}

	int mid = (nodeLeft + nodeRight) >> 1;
	init(node << 1, nodeLeft, mid);
	init((node << 1) + 1, mid + 1, nodeRight);

	tree[node] = tree[node << 1] * tree[(node << 1) + 1];
}

void update(int node, int nodeLeft, int nodeRight, int idx, int val) {
	if (idx < nodeLeft || nodeRight < idx) return;

	if (nodeLeft == nodeRight) {
		tree[node] = convert(val);
		return;
	}

	int mid = (nodeLeft + nodeRight) >> 1;
	update(node << 1, nodeLeft, mid, idx, val);
	update((node << 1) + 1, mid + 1, nodeRight, idx, val);

	tree[node] = tree[node << 1] * tree[(node << 1) + 1];
}

int query(int node, int nodeLeft, int nodeRight, int queryLeft, int queryRight) {
	if (queryRight < nodeLeft || nodeRight < queryLeft)
		return 1;

	if (queryLeft <= nodeLeft && nodeRight <= queryRight)
		return tree[node];

	int mid = (nodeLeft + nodeRight) >> 1;

	int l = query(node << 1, nodeLeft, mid, queryLeft, queryRight);
	int r = query((node << 1) + 1, mid + 1, nodeRight, queryLeft, queryRight);

	return l * r;
}

int main() {
	int n, k;
	while (scanf("%d %d", &n, &k) != EOF) {
		char op; int x, y;
		for (int i = 0; i < n; ++i)
			scanf("%d ", &arr[i]);

		init(1, 0, n - 1);

		for (int i = 0; i < k; ++i) {
			scanf("%c %d %d ", &op, &x, &y);

			if (op == 'P') {
				int ret = query(1, 0, n - 1, x - 1, y - 1);
				if (ret > 0) printf("+");
				else if (ret < 0) printf("-");
				else printf("0");
			}
			else
				update(1, 0, n - 1, x - 1, y);
		}
		puts("");
	}

	return 0;
}