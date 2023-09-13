#include <iostream>
#include <vector>
#include <queue>

using std::cin;
using std::cout;
using std::vector;
using std::queue;

int degree[1'005], n, m;
vector<int> arr[1'005];
vector<int> rst;

int main() {
	// std::ios::sync_with_stdio(0), cin.tie(0)
	cin >> n >> m;

	// input
	for (int i = 0; i < m; ++i) {
		int l, x; cin >> l;
		vector<int> temp;

		for (int j = 0; j < l; ++j) {
			cin >> x; temp.emplace_back(x);
		}

		for (int j = 1; j < l; ++j) {
			++degree[temp[j]];
			arr[temp[j - 1]].emplace_back(temp[j]);
		}
	}
	
	// topological sort
	queue<int> q;
	for (int i = 1; i <= n; ++i)
		if (!degree[i]) q.emplace(i);
	
	while (!q.empty()) {
		int curr = q.front(); q.pop();
		rst.emplace_back(curr);

		for (const int& x : arr[curr]) {
			--degree[x];
			if (!degree[x]) q.emplace(x);
		}
	}
	if (rst.size() != n) cout << 0;
	else for (const int& x : rst) cout << x << '\n';

}