#include <cstdio>
#include <queue>
#include <vector>
#include <stack>
#define MAX 1005
#define inf 0x7fffffff
int n, m;

struct edge_t {
	int node, weight;

	bool operator<(const edge_t& x) const {
		return weight > x.weight;
	}

	bool operator!=(const edge_t& x) const {
		return node != x.node || weight != x.weight;
	}

	bool operator==(const edge_t& x) const {
		return node == x.node && weight == x.weight;
	}
};

std::vector<std::vector<edge_t>> arr(MAX); // 양방향 그래프
int dist[MAX];
//edge_t prev[MAX]; // ::prev[i] := i로 오기 직전의 도로
edge_t target = { -1,-1 };
bool start = true; // 처음 다잌을 돌릴 때만 ::prev를 저장하기 위하여
int pv2 = -1, pv1 = -1;
int prev[MAX];

void dijkstra(int curr) {
	for (int i = 1; i <= n; ++i) dist[i] = inf;
	dist[curr] = 0;

	std::priority_queue<edge_t> pq;
	pq.push({ curr, 0 });

	while (!pq.empty()) {
		edge_t curr = pq.top(); pq.pop();

		if (dist[curr.node] < curr.weight) continue;

		for (const edge_t& x : arr[curr.node]) {
			if ((x.node == pv1 && curr.node == pv2) || (x.node == pv2 && curr.node == pv1)) continue; // 제거할 길이면 pass

 			int d = dist[curr.node] + x.weight;
			if (dist[x.node] <= d) continue;
			//printf("curr : %d, x = <%d,%d>, dist = %d\n", curr.node, x.node, x.weight, d);

			dist[x.node] = d;
			if (start) prev[x.node] = curr.node;

			pq.push({ x.node, d });
		}
	}
}

int main() {
	// freopen("input.txt", "r", stdin);
	scanf("%d %d", &n, &m); 
	
	int u, v, w;

	for (int i = 0; i < m; ++i) {
		scanf("%d %d %d", &u, &v, &w);
		arr[u].push_back({ v,w });
		arr[v].push_back({ u,w });
	}
	

	// 먼저 최단 경로를 찾음
	dijkstra(1);
	start = false;
	int ans = dist[n];
	prev[1] = -1;


	// 경로에 있는 것들을 하나씩 지워보며 dijkstra
	pv1 = n, pv2 = prev[n];
	while (pv1 != -1) {

		dijkstra(n);
	
		ans = ans > dist[1] ? ans : dist[1];

		
		pv1 = pv2;
		pv2 = prev[pv1];
	}

	printf("%d\n", ans);
}