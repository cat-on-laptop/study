#include <iostream>

typedef long long ll;
using std::cin;
using std::cout;

int arr[100'005];
ll tree[400'005];

void init(int node, int nodeLeft, int nodeRight) {
	if (nodeLeft == nodeRight) {
		tree[node] = arr[nodeLeft];
		return;
	}

	int mid = (nodeLeft + nodeRight) >> 1;
	
	init(node << 1, nodeLeft, mid);
	init((node << 1) + 1, mid + 1, nodeRight);

	tree[node] = tree[node << 1] + tree[(node << 1) + 1];
}

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

ll get_value(int node, int nodeLeft, int nodeRight, int queryLeft, int queryRight) {
	if (queryRight < nodeLeft || nodeRight < queryLeft)
		return 0;

	if (queryLeft <= nodeLeft && nodeRight <= queryRight)
		return tree[node];

	int mid = (nodeLeft + nodeRight) >> 1;

	ll l = get_value(node << 1, nodeLeft, mid, queryLeft, queryRight);
	ll r = get_value((node << 1) + 1, mid + 1, nodeRight, queryLeft, queryRight);

	return l + r;
}

int main() {
	std::ios::sync_with_stdio(0), cin.tie(0);

	int n, m; cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	init(1, 0, n - 1);

//	        15
//		6		9
//	3	3	4	5
//1  2    

	int x, y, a, b;
	for (int i = 0; i < m; ++i) {
		cin >> x >> y >> a >> b; 
		x > y ? cout << get_value(1, 0, n - 1, y - 1, x - 1) << '\n' : cout << get_value(1, 0, n - 1, x - 1, y - 1) << '\n';
		update(1, 0, n - 1, a - 1, b);
	}

	return 0;
}