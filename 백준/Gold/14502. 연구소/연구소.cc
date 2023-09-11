#include <iostream>
#include <cstring>
#include <queue>

using std::cin;
using std::cout;
using std::queue;

int arr[8][8], modified[8][8];
bool visited[8][8];
int n, m;
const int dir[4][2] = { -1,0, 1,0, 0,-1, 0,1 };


struct vertex_t {
	int row, col;

	vertex_t(int _row, int _col) : row(_row), col(_col) {}
};

int bfs() {
	memset(visited, false, sizeof(visited));
	queue<vertex_t> q;
	int cnt = 0;

	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			if (arr[i][j] == 2) {
				visited[i][j] = true;
				q.emplace(i, j);
			}

	while (!q.empty()) {
		vertex_t curr = q.front(); q.pop();

		for (int d = 0; d < 4; ++d) {
			int nr = curr.row + dir[d][0], nc = curr.col + dir[d][1];

			if (0 > nr || nr >= n || 0 > nc || nc >= m) continue;
			if (visited[nr][nc] || modified[nr][nc]) continue;

			visited[nr][nc] = true;
			q.emplace(nr, nc);
		}
	}

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (!visited[i][j] && !modified[i][j]) ++cnt;

	return cnt;
}

int dfs(int curr) {
	if (curr == 3) {
		return bfs();
	}

	int cnt = -1;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (!modified[i][j]) {
				modified[i][j] = 1;
				int ret = dfs(curr + 1);
				cnt = cnt < ret ? ret : cnt;
				modified[i][j] = 0;
			}
		}
	}

	return cnt;
}

int main() {
	std::ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) 
			cin >> arr[i][j];
		
	memcpy(modified, arr, sizeof(arr));

	// dfs로 벽 자리 확인 후 최댓값 출력
	cout << dfs(0);
}