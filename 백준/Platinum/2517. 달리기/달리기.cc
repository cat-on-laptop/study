#include <cstdio>
#include <algorithm>

using std::sort;

struct runner_t {
	int idx, val;

	bool operator<(const runner_t& r) const {
		if (val < r.val) return true;
		if (val > r.val) return false;

		if (idx < r.idx) return true;
		if (idx > r.idx) return false;

		return false;
	}
}arr[500'005];

int n, tree[2'000'005];

void update(int node, int nodeLeft, int nodeRight, int idx) {
	if (idx < nodeLeft || nodeRight < idx) return;

	if (nodeLeft == nodeRight) {
		tree[node] = 1;
		return;
	}

	int mid = (nodeLeft + nodeRight) >> 1;

	update(node << 1, nodeLeft, mid, idx);
	update((node << 1) + 1, mid + 1, nodeRight, idx);
	tree[node] = tree[node << 1] + tree[(node << 1) + 1];
}

int query(int node, int nodeLeft, int nodeRight, int queryLeft, int queryRight) {
	if (queryRight < nodeLeft || nodeRight < queryLeft) return 0;
	if (queryLeft <= nodeLeft && nodeRight <= queryRight) return tree[node];

	int mid = (nodeLeft + nodeRight) >> 1;

	int left = query(node << 1, nodeLeft, mid, queryLeft, queryRight);
	int right = query((node << 1) + 1, mid + 1, nodeRight, queryLeft, queryRight);
	return left + right;
}

int main() {
	// freopen("input.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &arr[i].val);
		arr[i].idx = i;
	}

	// 좌표 압축
	sort(arr, arr + n);
	for (int i = 0; i < n; ++i)
		arr[i].val = i + 1;
	sort(arr, arr + n, [](const runner_t& x, const runner_t& y) {
		if (x.idx < y.idx) return true;
		if (x.idx > y.idx) return false;
		if (x.val < y.val) return true;
		if (x.val > y.val) return false;
		return false; 
	});


	for (int i = 0; i < n; ++i) {
		printf("%d\n", i - query(1, 0, n - 1, 0, arr[i].val) + 1);
		update(1, 0, n - 1, arr[i].val);
	}

	return 0;
}