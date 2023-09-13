#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using std::cin;
using std::cout;
using std::vector;
using std::priority_queue;
using std::greater;

int degree[32'005], n, m;
vector<int> arr[32'005];

int main() {
	std::ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;

	int a, b;

	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		++degree[b];
		arr[a].emplace_back(b);
	}

	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 1; i <= n; ++i) if (!degree[i]) pq.emplace(i);

	while (!pq.empty()) {
		int curr = pq.top(); pq.pop();
		cout << curr << ' ';

		for (const int& x : arr[curr]) {
			--degree[x];
			if (!degree[x]) pq.emplace(x);
		}
	}

}