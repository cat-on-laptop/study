#include <iostream>
#include <vector>
#include <queue>
#define MAX 0x7fffffffffffffff

using std::cin;
using std::cout;
using std::priority_queue;
using std::vector;

struct edge_t {
	int node;
	long long weight;

	edge_t(int n, long long w) : node(n), weight(w) {}

	bool operator<(const edge_t& e) const {
		return weight > e.weight;
	}
};

vector<edge_t> arr[100'005];
bool able[100'005];
int n, m;
long long dist[100'005];

void dijkstra() {
	for (int i = 0; i < n; ++i) dist[i] = MAX;

	priority_queue<edge_t> pq;
	pq.emplace(0, 0);
	dist[0] = 0;

	while (!pq.empty()) {
		edge_t curr = pq.top(); pq.pop();

		if (dist[curr.node] < curr.weight) continue;

		for (const edge_t& e : arr[curr.node]) {
			long long temp = dist[curr.node] + e.weight;

			if (dist[e.node] <= temp) continue;
			if (e.node != n - 1 && able[e.node]) continue;
			
			dist[e.node] = temp;
			pq.emplace(e.node, temp);
		}
	}
}

int main() {
	// freopen("input.in", "r", stdin);
	std::ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
		cin >> able[i];
	
	int a, b, c;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b >> c;
		arr[a].emplace_back(b, c);
		arr[b].emplace_back(a, c);
	}

	dijkstra();

	cout << (dist[n - 1] == MAX ? -1 : dist[n - 1]);
	return 0;
}