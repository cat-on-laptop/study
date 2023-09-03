#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using std::cin;
using std::cout;
using std::priority_queue;

int main() {
	// freopen("input.txt", "r", stdin);
	std::ios::sync_with_stdio(0), cin.tie(0);

	int t; cin >> t;
	for (int tc = 0; tc < t; ++tc) {
		priority_queue<int, std::vector<int>, std::greater<int>> big;
		priority_queue<int, std::vector<int>, std::less<int>> small;
		int n, x; cin >> n;
		cout << ((n + 1) >> 1) << '\n';

		for (int i = 1; i <= n; ++i) {
			cin >> x;
			if (big.size() == small.size()) {
				big.push(x); small.push(big.top()); big.pop();
			}
			else {
				small.push(x); big.push(small.top()); small.pop();
			}

			if (i & 1) cout << small.top() << ' ';
		}
		cout << '\n';

	}
}