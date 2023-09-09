#include <iostream>
#include <queue>
#include <vector>

using std::cin;
using std::cout;
using std::priority_queue;
using std::vector;

struct edge_t {
	int x, w;

	edge_t(int _x, int _w) :x(_x), w(_w) {}

	bool operator<(const edge_t &target) const {
		return w > target.w;
	}
};

vector<edge_t> arr[805];
int dist1[805], dist2[805];
int n, e;
int must1, must2;

inline int min(int x, int y) {
	return x < y ? x : y;
}

void dijkstra(int start, int idx) {
	// idx 1 -> must1에서 출발, idx 2 -> must2에서 출발
	if(idx & 1) for(int i = 1; i <= n; ++i) dist1[i] = 0x7fffffff;
	else for(int i = 1; i <= n; ++i) dist2[i] = 0x7fffffff;

	if (idx &1) dist1[start] = 0;
	else dist2[start] = 0;

	priority_queue<edge_t> pq; pq.emplace(start, 0);

	while(!pq.empty()) {
		edge_t curr = pq.top(); pq.pop();

		if(idx & 1) {
			if(dist1[curr.x] < curr.w) continue;

			for(const edge_t & e: arr[curr.x]) {
				if(dist1[e.x] <= dist1[curr.x] + e.w) continue;

				dist1[e.x] = dist1[curr.x] + e.w;
				pq.emplace(e.x, dist1[e.x]);
			}


		}
		else {
			if(dist2[curr.x] < curr.w) continue;

			for(const edge_t & e: arr[curr.x]) {
				if(dist2[e.x] <= dist2[curr.x] + e.w) continue;

				dist2[e.x] = dist2[curr.x] + e.w;
				pq.emplace(e.x, dist2[e.x]);
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(0), cin.tie(0);
	// input
	cin >> n >> e;
	int a, b, c;

	for(int i = 0; i < e; ++i) {
		cin >> a >> b >> c;
		arr[a].emplace_back(b, c);
		arr[b].emplace_back(a, c);
	}
	cin >> must1 >> must2;

	dijkstra(must1, 1);
	dijkstra(must2, 2);

	int ans = 0x7fffffff;

	// 1 -> must1 -> must2 -> n
	if(dist1[1] != 0x7fffffff && dist1[must2] != 0x7fffffff && dist2[n] != 0x7fffffff) ans = dist1[1] + dist1[must2] + dist2[n];

	// 1 -> must2 -> must1 -> n
	if(dist2[1] != 0x7fffffff && dist2[must1] != 0x7fffffff && dist1[n] != 0x7fffffff) ans = min(ans, dist2[1] + dist2[must1] + dist1[n]);

	ans == 0x7fffffff ? cout << -1 : cout << ans;
}