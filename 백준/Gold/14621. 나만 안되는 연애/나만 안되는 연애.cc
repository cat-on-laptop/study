#include <iostream>
#include <queue>
#define MAX 1005

using std::cin;
using std::cout;
using std::priority_queue;

struct edge_t {
	int x, y, weight;

	edge_t(int _x, int _y, int _weight) : x(_x), y(_y), weight(_weight) {}

	bool operator<(const edge_t& x) const {
		return weight > x.weight;
	}
};

int n, m;
int parent[MAX];
char DAT[MAX];
priority_queue<edge_t> pq;

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
	int px = find(x), py = find(y);

	if (px == py) return;
	parent[py] = px;
}

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) cin >> DAT[i];
	
	int x, y, w;
	for (int i = 0; i < m; ++i) {
		cin >> x >> y >> w;
		--x, --y;
		if (DAT[x] == DAT[y]) continue;
		pq.emplace(x, y, w);
	}
}

void process() {
	for (int i = 0; i < n; ++i) parent[i] = i;

	int tot = 0, cnt = 0;
	while (!pq.empty()) {
		edge_t curr = pq.top(); pq.pop();

		if (find(curr.x) == find(curr.y)) continue;

		merge(curr.x, curr.y);
      	++cnt;
		tot += curr.weight;
	}

	int p = find(0);
	
	cnt == n-1 ?cout << tot : cout <<-1;
}

int main() {
	// freopen("input.txt", "r", stdin);
	std::ios::sync_with_stdio(0), cin.tie(0);
	input();
	process();
}