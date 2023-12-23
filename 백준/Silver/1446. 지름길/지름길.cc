/*
	d 이하인 모든 정점에 대해 거리가 1인 edge를 추가 -> 일반 상태
	이후 입력에 대해 지름 길 추가하고 dijkstra!!
*/

#include <iostream>
#include <vector>
#include <queue>
#define MAX 0x7fffffff

using std::cin;
using std::cout;
using std::vector;
using std::priority_queue;

struct edge_t {
	int node, weight;

	edge_t(int n, int w) : node(n), weight(w) {}

	bool operator<(const edge_t& e) const {
		if (weight > e.weight) return true;
		return false;
	}
};

vector<edge_t> arr[10'005];
int dist[10'005];
int n, d;

void dijkstra() {
	priority_queue<edge_t> pq;
	for (int i = 0; i <= d; ++i) dist[i] = MAX;
	dist[0] = 0;
	pq.emplace(0, 0);

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
	std::ios::sync_with_stdio(0), cin.tie(0);

	cin >> n >> d;
	int a, b, c;
	for (int i = 0; i < n; ++i) {
		cin >> a >> b >> c;

		if (b > d) continue;
		arr[a].emplace_back(b, c);
	}

	for (int i = 0; i < d; ++i)
		arr[i].emplace_back(i + 1, 1);

	dijkstra();
	cout << dist[d];

	return 0;
}