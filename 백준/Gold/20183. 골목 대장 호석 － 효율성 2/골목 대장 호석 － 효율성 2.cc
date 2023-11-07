#include <iostream>
#include <queue>
#include <vector>
#define INF 0x7fffffffffffffff

using namespace std;
typedef long long ll;

struct edge_t {
	int node;
	ll weight;

	bool operator< (const edge_t& e) const {
		return weight > e.weight;
	}
};

int n, m, a, b, val;
ll c;
ll dist[100'005];

vector<edge_t> arr[100'005];

inline int max(int x, int y) {
	return x > y ? x : y;
}

bool dijkstra(int offset) {
	for (int i = 1; i <= n; ++i)
		dist[i] = INF;

	dist[a] = 0;
	priority_queue<edge_t> pq; 
	pq.push({ a,0 });

	while (!pq.empty()) {
		edge_t curr = pq.top(); pq.pop();

		if (dist[curr.node] < curr.weight) continue;

		for (const edge_t& e : arr[curr.node]) {
			if (e.weight > offset)
				continue;

			if (dist[e.node] <= dist[curr.node] + e.weight)
				continue;

			dist[e.node] = dist[curr.node] + e.weight;
			pq.push({ e.node, dist[e.node] });
		}
	}

	return dist[b] <= c;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	// freopen("input.txt", "r", stdin);
	cin >> n >> m >> a >> b >> c;
	
	int x, y, z;

	for (int i = 0; i < m; ++i) {
		cin >> x >> y >> z;
		arr[x].push_back({ y,z });
		arr[y].push_back({ x,z });
		val = max(val, z + 1);
	}

	int l = 1, r = val, m;

	// fffffffffffttttttttt 인 첫 t를 찾는 이분 탐색
	// 구간 [l, r)에 대하여 탐색

	while (l != r) {
		m = l + ((r - l) >> 1);
		dijkstra(m) ? r = m : l = m + 1;
	}

	r == val ? cout << -1 : cout << l;

	return 0;
}
