#include <iostream>

using std::cin;
using std::cout;

int parent[100'005], level[100'005];

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
	int px = find(x), py = find(y);

	if (px == py) return;

	parent[px] = py;

}

int main() {
	std::ios::sync_with_stdio(0), cin.tie(0);

	int g, p; cin >> g >> p;
	for (int i = 1; i <= g; ++i) parent[i] = i;

	int cnt = 0, x;
	for (int i = 1; i <= p; ++i) {
		cin >> x;
		
		int port = find(x);
		if (port) {
			++cnt;
			merge(port, port - 1);
		}
		else break;
	}
	cout << cnt;
}