#include <iostream>
#include <queue>
#include <vector>
#define MAX 0x7fffffff

using std::cin;
using std::cout;
using std::vector;
using std::priority_queue;

struct edge_t {
	int node, weight;

	edge_t(int n, int w) : node(n), weight(w) {}

	bool operator<(const edge_t& e) const {
		return weight > e.weight;
	}
};

int n, d, c;
vector<edge_t> arr[100'005];
int dist[100'005];

inline int max(int x, int y) {
	return x > y ? x : y;
}

void dijkstra(int s) {
	dist[s] = 0;
	priority_queue<edge_t> pq;
	pq.emplace(s, 0);

	while (!pq.empty()) {
		edge_t curr = pq.top(); pq.pop();

		if (dist[curr.node] < curr.weight) continue;

		for (const edge_t& e : arr[curr.node]) {
			if (dist[e.node] <= dist[curr.node] + e.weight) continue;

			dist[e.node] = dist[curr.node] + e.weight;

			pq.emplace(e.node, dist[e.node]);
		}
	}
}

int main() {
	// freopen("input.in", "r", stdin);
	int t; cin >> t;

	for (int tc = 0; tc < t; ++tc) {
		cin >> n >> d >> c;
		// init
		for (int i = 0; i <= n; ++i) {
			dist[i] = MAX;
			arr[i].clear();
		}

		int a, b, s;
		for (int i = 0; i < d; ++i) {
			cin >> a >> b >> s;
			arr[b].emplace_back(a, s);
		}

		dijkstra(c);
		int cnt = 0, val = -1;
		
		for (int i = 0; i <= n; ++i) {
			if (dist[i] == MAX) continue;
			
			++cnt;
			val = max(val, dist[i]);
		}

		cout << cnt << ' ' << val << '\n';
	}

	return 0;
}