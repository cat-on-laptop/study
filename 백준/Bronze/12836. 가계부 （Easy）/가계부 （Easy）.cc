#include <iostream>
#define endl '\n'

using std::cin;
using std::cout;

class Segtree {
private:
	int offset;
	long long tree[4'000'005];

public:
	void init(int n) {
		for (offset = 1; offset < n; offset <<= 1);
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
		long long tot = 0;

		while (a <= b) {
			if (a & 1) tot += tree[a];
			if (!(b & 1)) tot += tree[b];

			a = (a + 1) >> 1;
			b = (b - 1) >> 1;
		}

		return tot;
	}
}tree;

int main() {
	std::ios::sync_with_stdio(0), cin.tie(0);
	// freopen("input.in", "r", stdin);

	int n, q; cin >> n >> q;
	tree.init(n);
	
	int op, a, b;
	for (int i = 0; i < q; ++i) {
		cin >> op >> a >> b;

		if (op & 1) 
			tree.update(a, b);		
		else 
			cout << tree.query(a, b) << endl;	
	}

	return 0;
}