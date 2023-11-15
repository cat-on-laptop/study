#include <iostream>

using std::cin;
using std::cout;

const int MOD = 1'000'000'007;

class Segtree {
private:
	long long tree[530'005];
	int offset;
public:
	void init(int n) {
		for (offset = 1; offset < n; offset <<= 1);
		for (int i = 0; i < (offset * 2); ++i)
			tree[i] = 0;
	}

	void update(int idx, int val) {
		idx += offset;
		tree[idx] += val;
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

	long long val() {
		return tree[1];
	}
};

Segtree cnt, coord;

int main() {
	// freopen("input.in", "r", stdin);
	std::ios::sync_with_stdio(0), cin.tie(0);
	int n; cin >> n;

	cnt.init(200'000);
	coord.init(200'000);

	int x; long long ans = 1;
	
	for (int i = 0; i < n; ++i) {
		cin >> x;
		if (i) {
			long long pre = (cnt.query(0, x - 1) * x - coord.query(0, x - 1)) % MOD;
			long long post = (coord.query(x + 1, 200'000) - cnt.query(x + 1, 200'000) * x) % MOD;
			ans = (ans * ((pre + post) % MOD)) % MOD;
		}
		cnt.update(x, 1);
		coord.update(x, x);
	}
	cout << ans;
	return 0;
}