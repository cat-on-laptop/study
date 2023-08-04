#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 105

using namespace std;

int v, e, k, a, b;

struct edge_t {
	int node, weight;

	bool operator<(const edge_t& x) const {
		//if (x.weight == weight) return cnt > x.cnt;
		return weight > x.weight;
	}
};

vector<edge_t> arr[MAX];
int dist[MAX];
int cnt[MAX];

void dijkstra(int start = 1) {
	for (int i = 1; i <= v; ++i) dist[i] = cnt[i] = 0x7fffffff;
	dist[start] = 0;
	cnt[start] = 1;

	priority_queue<edge_t> pq;
	pq.push({ start,0 });

	while (!pq.empty()) {
		edge_t curr = pq.top(); pq.pop();

		if (dist[curr.node] < curr.weight) continue;

		for (const edge_t& x : arr[curr.node]) {
			int l = dist[curr.node] + x.weight;

			if (dist[x.node] < l ) continue;
			if (dist[x.node] == l) {
				cnt[x.node] = min(cnt[x.node], cnt[curr.node] + 1);
				continue;
			}

			dist[x.node] = l;
			cnt[x.node] = cnt[curr.node] + 1;
			pq.push({ x.node, l });
		}
		//cout << "curr : " << curr.node << " cnt : " << cnt[curr.node] << endl;
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> v >> e;

	int a, b, c, d, f;

	for (int i = 0; i < e; ++i) {
		cin >> a >> b >> c >> d >> f;
		int fee = c;
		if (f > 10) fee += (f - 10) * d;
		arr[a].push_back({ b,fee });
	}
	

	dijkstra();
	//for (int i = 1; i <= v; ++i) cout << cnt[i] << ' ';
	//cout << endl;
	if (dist[v] == 0x7fffffff) cout << "It is not a great way.";
	else cout << dist[v] << ' ' << cnt[v];
	
	//cout << d;
}