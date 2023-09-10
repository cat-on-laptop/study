#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::sort;

int arr[15];
int a[15];
int n, m;


void f(int curr, int idx) {
	if(curr == m) {
		for(int i = 0; i < m; ++i) cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	for(int i = idx; i < n; ++i) {

		arr[curr] = a[i];
		f(curr + 1, i);
	}
}

int main() {
	std::ios::sync_with_stdio(0), cin.tie(0);
	// input
	cin >> n >> m;
	for(int i = 0; i < n; ++i) cin >> a[i];
	sort(a, a + n);

	f(0, 0);
}