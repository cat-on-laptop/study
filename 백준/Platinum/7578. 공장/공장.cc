#include <cstdio>

int arr[500'005];
int idx[1'000'005];

class Segtree {
	long long tree[1 << 20];
	int offset;

public:
	void init(int n) {
		for (offset = 1; offset < n; offset <<= 1);
	}

	void update(int idx) {
		idx += offset;
		++tree[idx];
		idx >>= 1;

		while (idx) {
			tree[idx] = tree[idx << 1] + tree[idx << 1 | 1];
			idx >>= 1;
		}
	}

	long long query(int a, int b) {
		a += offset; b += offset;
		long long ret = 0;

		while (a <= b) {
			if (a & 1) ret += tree[a];
			if (!(b & 1)) ret += tree[b];

			a = (a + 1) >> 1;
			b = (b - 1) >> 1;
		}

		return ret;
	}
};

Segtree tree;

int main() {
	// freopen("input.in", "r", stdin);
	int n, x; scanf("%d", &n);

	for (int i = 0; i < n; ++i)
		scanf("%d", &arr[i]);

	for (int i = 0; i < n; ++i) {
		scanf("%d", &x); 
		idx[x] = i;
	}

	tree.init(n);
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		if (i) ans += tree.query(idx[arr[i]], n);
		tree.update(idx[arr[i]]);
	}

	printf("%lld", ans);
	
	return 0;
}