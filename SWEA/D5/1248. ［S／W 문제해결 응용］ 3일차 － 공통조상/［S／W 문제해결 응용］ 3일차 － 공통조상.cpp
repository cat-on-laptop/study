#include <iostream>
#include <vector>
#include <cstring>

using std::cin;
using std::cout;
using std::vector;

int v, e, x, y;
int parent[10005];
vector<int> ancestorX, ancestorY;
vector<vector<int>> arr;

void init() {
	memset(parent, 0, sizeof(parent));
	ancestorX.clear(); ancestorY.clear();
}

void input() {
	int a, b;
	cin >> v >> e >> x >> y;
	
	arr = vector<vector<int>>(v + 1, vector<int>());
	for (int i = 0; i < e; ++i) {
		cin >> a >> b;
		arr[a].emplace_back(b);
		parent[b] = a;
	}
}

void getAncestor(int x, vector<int>& arr) {
	if (parent[x]) getAncestor(parent[x], arr);

	arr.emplace_back(x);
}

int dfs(int curr) {
	int cnt = 1;
	for (const int& x : arr[curr]) {
		cnt += dfs(x);
	}

	return cnt;
}

void run(int tc) {
	getAncestor(x, ancestorX);
	getAncestor(y, ancestorY);

	int ans = 1;
	for (int i = 0; i < ancestorX.size(); ++i) {
		if (ancestorX[i] != ancestorY[i]) break;
		ans = ancestorX[i];
	}

	cout << "#" << tc << ' ' << ans << ' ' << dfs(ans) << '\n';
}

int main() {
	std::ios::sync_with_stdio(0), cin.tie(0);
	int t; cin >> t;

	for (int tc = 1; tc <= t; ++tc) {
		init();
		input();
		run(tc);
	}
	return 0;
}