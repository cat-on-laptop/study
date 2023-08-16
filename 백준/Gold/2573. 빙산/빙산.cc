#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <cstring>
#define MAX 505

using std::cin;
using std::cout;
using std::queue;

const int dir[4][2] = { -1,0, 1,0, 0,-1, 0,1 };
int n, m;
int arr[MAX][MAX];
int temp[MAX][MAX]; 
bool visited[MAX][MAX]; // visited[row][col] := row, col의 방문 여부


struct node_t {
	int row, col;

	node_t(int _row, int _col) : row(_row), col(_col) {}
};

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> arr[i][j];
	
}

int cnt(int row, int col) {
	// row, col 좌표에 인접한 영역에 바다가 얼마나 있는지 체크
	int tot = 0;
	for (int d = 0; d < 4; ++d) {
		int nr = row + dir[d][0], nc = col + dir[d][1];

		if (0 > nr || nr >= n || 0 > nc || nc >= m) continue;

		if (arr[nr][nc]) continue;

		++tot;
	}
	return tot;
}

void bfs(int row, int col) {
	queue<node_t> q;
	q.emplace(row, col);
	visited[row][col] = true;

	while (!q.empty()) {
		node_t curr = q.front(); q.pop();

		for (int d = 0; d < 4; ++d) {
			int nr = curr.row + dir[d][0], nc = curr.col + dir[d][1];

			if (0 > nr || nr >= n || 0 > nc || nc >= m) continue;
			if (visited[nr][nc] || !arr[nr][nc]) continue;

			visited[nr][nc] = true;
			q.emplace(nr, nc);
		}
	}
}

void process() {
	// 빙산들을 찾기 위한 bfs
	int row, col;
	for(int i = 0; i < n;++i)
		for(int j=0;j<m;++j)
			if (arr[i][j]) {
				row = i, col = j;
				break;
			}

	queue<node_t> q;
	queue<node_t> candidate;
	q.emplace(row, col);
	visited[row][col] = true;
	int cYear = 0;
	bool flag;

	while (true) {
		++cYear;
		flag = false;
		while (!q.empty()) {
			flag = true;
			node_t curr = q.front(); q.pop();
			candidate.emplace(curr);

			for (int d = 0; d < 4; ++d) {
				int nr = curr.row + dir[d][0], nc = curr.col + dir[d][1];

				if (0 > nr || nr >= n || 0 > nc || nc >= m) continue;
				if (visited[nr][nc] || !arr[nr][nc]) continue;

				visited[nr][nc] = true;
				q.emplace(nr, nc);
			}
		}

		memset(temp, 0, sizeof(temp));

		while (!candidate.empty()) {
			node_t curr = candidate.front(); candidate.pop();

			int year = cnt(curr.row, curr.col);

			temp[curr.row][curr.col] = arr[curr.row][curr.col] - year > 0 ? arr[curr.row][curr.col] - year : 0;

			if (temp[curr.row][curr.col]) q.emplace(curr);
			
		}

		memcpy(arr, temp, sizeof(arr));

		memset(visited, 0, sizeof(visited));
		int num = 0;

		//for (int i = 0; i < n; ++i) {
		//	for (int j = 0; j < m; ++j) cout << arr[i][j] << ' ';
		//	cout << std::endl;
		//}
		//puts("");

		for(int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) 
				if (arr[i][j] && !visited[i][j]) {
					++num; bfs(i, j);
				}
		//cout << num << '\n';

		if (num >= 2) {
			cout << cYear;
			return;
		}

		if (num == 0) {
			cout << 0;
			return;
		}
			
	}

	return;

}

int main() {
	// freopen("input.txt", "r", stdin);
	input();
	process();
}