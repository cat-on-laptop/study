#include <iostream>

using std::cin;
using std::cout;

int arr[15];
int n, m;

void f(int curr, int idx) {
	if(curr == m) {
		for(int i = 0; i < m; ++i) cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	for(int i = idx; i <= n; ++i) {
		arr[curr] = i;
		f(curr + 1, i + 1);
	}
}

int main() {
	std::ios::sync_with_stdio(0), cin.tie(0);
	// input
	cin >> n >> m;

	f(0, 1);
}