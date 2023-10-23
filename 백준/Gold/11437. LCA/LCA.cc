#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>

using std::vector;

vector<int> arr[50'005];
int n, m;
bool visited[50'005];
int parent[17][50'005];
int depth[50'005];

void dfs(int curr = 1) {
	visited[curr] = true;

	for (const int& x : arr[curr]) {
		if (!visited[x]) {
			parent[0][x] = curr;
			depth[x] = depth[curr] + 1;
			dfs(x);
		}
	}
}

int lca(int x, int y) {
	// x를 더 깊게
	if (depth[y] > depth[x]) {
		int temp = x;
		x = y;
		y = temp;
	}
	
	// depth 맞추기
	for (int i = 16; i >= 0; --i) 
		if (depth[x] - depth[y] >= (1 << i))
			x = parent[i][x];
	
	if (x == y)
		return x;

	// lca 찾기
	for(int i = 16; i >= 0; --i)
		if (parent[i][x] != parent[i][y]) {
			x = parent[i][x];
			y = parent[i][y];
		}

	return parent[0][x];
}

int main() {
	// freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	int x, y;
	for (int i = 0; i < n - 1; ++i) {
		scanf("%d %d", &x, &y);
		arr[x].push_back(y);
		arr[y].push_back(x);
	}

	dfs();

	// pre-processing

	for (int i = 1; i < 17; ++i)
		for (int j = 1; j <= n; ++j)
			parent[i][j] = parent[i - 1][parent[i - 1][j]];

	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d %d", &x, &y);
		printf("%d\n", lca(x, y));
	}
}