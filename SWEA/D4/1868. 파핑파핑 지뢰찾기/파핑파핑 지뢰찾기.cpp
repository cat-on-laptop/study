#include <iostream>
#include <queue>

using std::cin;
using std::cout;
using std::queue;
using std::pair;


int arr[305][305];
int n;
const int dir[8][2] = { -1,0, -1,1, 0,1, 1,1, 1,0, 1,-1, 0,-1, -1,-1};

void input() {
	cin >> n;
	char x;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			cin >> x;
			if (x == '.') arr[i][j] = -1;
			else arr[i][j] = -2;
		}
}

bool check(int row, int col) {

	for (int d = 0; d < 8; ++d) {
		int nr = row + dir[d][0], nc = col + dir[d][1];

		if (0 > nr || nr >= n || 0 > nc || nc >= n) continue;
		if (arr[nr][nc] == -2) return false;
	}
	return true;
}

void click(int row, int col) {
	queue<pair<int, int>> q;
	q.emplace(row, col);

	arr[row][col] = 0; // visited

	while (!q.empty()) {
		pair<int, int> curr = q.front(); q.pop();
		arr[curr.first][curr.second] = 0;

		for (int d = 0; d < 8; ++d) {
			int nr = curr.first + dir[d][0], nc = curr.second + dir[d][1];

			if (0 > nr || nr >= n || 0 > nc || nc >= n || arr[nr][nc] != -1) continue;

			if (check(nr, nc)) q.emplace(nr, nc);
			arr[nr][nc] = 0;
		}
	}
}

int run() {
	int cnt = 0;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (arr[i][j] == -1 && check(i, j)) click(i, j), ++cnt;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (arr[i][j] == -1) ++cnt;

	return cnt;
}

int main() {
	std::ios::sync_with_stdio(0), cin.tie(0);
	int t; cin >> t;

	for (int tc = 1; tc <= t; ++tc) {
		input();
		cout << "#" << tc << " " << run() << '\n';
	}
	return 0;
}