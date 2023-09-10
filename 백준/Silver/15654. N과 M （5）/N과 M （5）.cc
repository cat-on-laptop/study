#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::sort;

int arr[15];
int a[15];
int n, m;
bool used[15];

void f(int curr) {
	if(curr == m) {
		for(int i = 0; i < m; ++i) cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	for(int i = 0; i < n; ++i) {
		if(used[i]) continue;
		used[i] = true;
		arr[curr] = a[i];
		f(curr + 1);
		used[i] = false;
	}
}

int main() {
	std::ios::sync_with_stdio(0), cin.tie(0);
	// input
	cin >> n >> m;
	for(int i = 0; i < n; ++i) cin >> a[i];
	sort(a, a + n);

	f(0);
}