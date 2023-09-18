#include <iostream>
#include <queue>
#include <vector>
#define INF 0x7fffffffffffffff

using std::cin;
using std::cout;
using std::vector;
using std::priority_queue;

struct edge_t {
	int node, weight;

	edge_t(int _node, int _weight) : node(_node), weight(_weight) {}

	bool operator<(const edge_t& x) const {
		return weight > x.weight;
	}
};

vector<edge_t> arr[100'005];
vector<int> guma;
long long dist[100'005];
int n, m, k;

void input() {
	cin >> n >> m >> k;

	int u, v, c;
	for (int i = 0; i < m; ++i) {
		cin >> u >> v >> c;
		arr[v].emplace_back(u, c);
	}

	for (int i = 0; i < k; ++i) {
		cin >> c;
		guma.emplace_back(c);
	}
}

void run() {
	for (int i = 1; i <= n; ++i) dist[i] = INF;

	// 가상의 점 하나를 두고 각 출발점을 가중치가 0인 edge를 보고 dijkstra를 돌리면 출발점이
	// 여러개인 dijkstra로 동작

	// dijkstra
	priority_queue<edge_t> pq;
	for (const int& x : guma) dist[x] = 0, pq.emplace(x, 0);

	while (!pq.empty()) {
		edge_t curr = pq.top(); pq.pop();

		if (dist[curr.node] < curr.weight) continue;

		for (const edge_t& x : arr[curr.node]) {
			if (dist[x.node] <= dist[curr.node] + x.weight) continue;

			dist[x.node] = dist[curr.node] + x.weight;
			pq.emplace(x.node, dist[x.node]);
		}
	}

	long long node, len = -1;
	for (int i = 1; i <= n; ++i) 
		if (dist[i] > len) node = i, len = dist[i];
	
	cout << node << '\n' << len;
}

int main() {
	// freopen("input.txt", "r", stdin);
	std::ios::sync_with_stdio(0), cin.tie(0);
	input();
	run();
}