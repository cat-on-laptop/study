#include <iostream>

using std::cin;
using std::cout;

int parent[500'005], rank[500'005], n, m;

int find(int x) {
	if(parent[x] == x) return x;

	return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
	int px = find(x), py = find(y);

	if(px == py) return;

	if(rank[px] > rank[py]) parent[py] = px;
	else if(rank[px] < rank[py]) parent[px] = py;
	else parent[px] = py, rank[py]++;
}

int main () {
	std::ios::sync_with_stdio(0), cin.tie(0);

	cin >> n >> m;

	for(int i = 1; i <= n; ++i) parent[i] = i;
	int x, y;
	for(int i = 0; i < m; ++i) {
		cin >> x >> y;
		if(find(x) == find(y)) {
			cout << i + 1;
			return 0;
		}

		else merge(x, y);
	}

	cout << 0;

}