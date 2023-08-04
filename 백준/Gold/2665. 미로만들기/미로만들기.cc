// 벽이 있다면 1, 없다면 0으로 하고 최단 거리로 풀면 
// 벽을 몇번 부숴야 최단 거리로 올 수 있는지 알 수 있다

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#define MAX 55

using namespace std;

int arr[MAX][MAX];
int dist[MAX][MAX];
int n;

struct edge_t {
	int row, col, weight;

	bool operator<(const edge_t& x) const {
		return weight > x.weight;
	}
};

void dijkstra(int sRow = 0, int sCol = 0) {
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			dist[i][j] = 0x7fffffff;

	dist[sRow][sCol] = 0;
	priority_queue<edge_t> pq;
	pq.push({ sRow, sCol, 0 });

	const int dir[4][2] = { -1,0, 1,0, 0,-1, 0,1 };

	while (!pq.empty()) {
		edge_t curr = pq.top(); pq.pop();

		if (dist[curr.row][curr.col] < curr.weight) continue;

		for (int d = 0; d < 4; ++d) {
			int nr = curr.row + dir[d][0], nc = curr.col + dir[d][1];

			if (0 > nr || nr >= n || 0 > nc || nc >= n) continue;

			if (dist[nr][nc] <= dist[curr.row][curr.col] + arr[nr][nc]) continue;

			dist[nr][nc] = dist[curr.row][curr.col] + arr[nr][nc];
			pq.push({ nr, nc, dist[nr][nc] });
		}
		
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string x; cin >> x;

		for (int j = 0; j < n; ++j)
			arr[i][j] = x[j] - '0' == 1 ? 0 : 1;

	}

	dijkstra(0, 0);
	cout << dist[n - 1][n - 1];

}