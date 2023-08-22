#include <iostream>
#include <queue>
#define MAX 2005

using std::cin;
using std::cout;
using std::priority_queue;

struct node_t {
	int row, col;

	node_t(int _row = 0, int _col = 0) : row(_row), col(_col) {}
};

struct edge_t {
	int node, weight;

	edge_t(int _node, int _weight) : node(_node), weight(_weight) {}

	bool operator<(const edge_t& x) const {
		return weight > x.weight;
	}
};

int n, k;
int connected[MAX];
node_t DAT[MAX];

void input() {
	cin >> n >> k;

	int row, col;

	for (int i = 0; i < n; ++i) {
		cin >> row >> col;
		DAT[i] = node_t(row, col);
	}
}

int dist(node_t& x, node_t& y) {
	return (x.row - y.row) * (x.row - y.row) + (x.col - y.col) * (x.col - y.col);
}

void process() {
	int mst = 0;

	priority_queue<edge_t> pq;
	pq.emplace(0, 0);

	while (!pq.empty()) {
		edge_t curr = pq.top(); pq.pop();

		if (connected[curr.node]) continue;

		connected[curr.node] = true;
		mst += curr.weight;

		for (int i = 0; i < n; ++i) {
			if (i == curr.node) continue;

			if (connected[i]) continue;
			if (dist(DAT[i], DAT[curr.node]) < k) continue;
			pq.emplace(i, dist(DAT[curr.node], DAT[i]));
		}
	}
	for (int i = 0; i < n; ++i) \
		if (!connected[i]) {
			cout << -1; return;
		}
	cout << mst;
}

int main() {
	// freopen("input.txt", "r", stdin);
	std::ios::sync_with_stdio(0), cin.tie(0);
	input();
	process();
}