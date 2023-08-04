#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 1005

using namespace std;

int arr[MAX][MAX];
int dist[MAX][MAX];
int n, m;

struct edge_t {
	int row, col, weight;

	bool operator<(const edge_t& x) const {
		return weight > x.weight;
	}
};

void dijkstra(int sRow = 0, int sCol = 0) {
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			dist[i][j] = 0x7fffffff;

	dist[sRow][sCol] = arr[sRow][sCol];
	priority_queue<edge_t> pq;
	pq.push({ sRow, sCol, dist[sRow][sCol]});

	const int dir[4][2] = { -1,0, 1,0, 0,-1, 0,1 };

	while (!pq.empty()) {
		edge_t curr = pq.top(); pq.pop();

		if (dist[curr.row][curr.col] < 0) continue;
		if (dist[curr.row][curr.col] < curr.weight) continue;

		for (int d = 0; d < 4; ++d) {
			int nr = curr.row + dir[d][0], nc = curr.col + dir[d][1];

			if (0 > nr || nr >= n || 0 > nc || nc >= m) continue;
			if (arr[nr][nc] < 0) continue;

			if (dist[nr][nc] <= dist[curr.row][curr.col] + arr[nr][nc]) continue;

			dist[nr][nc] = dist[curr.row][curr.col] + arr[nr][nc];
			pq.push({ nr, nc, dist[nr][nc] });
		}
		
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> arr[i][j];

	dijkstra();
			
	//cout << endl;
	//for (int i = 0; i < n; ++i) {
	//	for (int j = 0; j < m; ++j)
	//		dist[i][j] == 0x7fffffff ? cout << "inf " : cout << dist[i][j] << "   ";
	//	cout << endl;
	//}


	dist[n - 1][m - 1] == 0x7fffffff ? cout << -1 : cout << dist[n - 1][m - 1];


}