#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>

using std::sort;

typedef long long ll;
struct node_t {
	int val, idx;

	bool operator< (const node_t& x) const {
		if (val < x.val) return true;
		if (val > x.val) return false;

		if (idx < x.idx) return true;
		if (idx > x.idx) return false;
		return false;
	}
};

int n;
ll tree[4'000'005];
node_t arr[1'000'005];

void update(int node, int nodeLeft, int nodeRight, int idx, int val) {
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

ll query(int node, int nodeLeft, int nodeRight, int queryLeft, int queryRight) {
	if (queryRight < nodeLeft || nodeRight < queryLeft)
		return 0;

	if (queryLeft <= nodeLeft && nodeRight <= queryRight)
		return tree[node];

	int mid = (nodeLeft + nodeRight) >> 1;

	ll left = query(node << 1, nodeLeft, mid, queryLeft, queryRight);
	ll right = query((node << 1) + 1, mid + 1, nodeRight, queryLeft, queryRight);

	return left + right;
}

int main() {
	// input
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &arr[i].val);
		arr[i].idx = i;
	}


	ll ans = 0;
	sort(arr, arr + n);
	for (int i = 0; i < n; ++i) {
		ans += query(1, 0, n - 1, arr[i].idx, n - 1);
		update(1, 0, n - 1, arr[i].idx, 1);
	}


	printf("%lld", ans);
	return 0;
}