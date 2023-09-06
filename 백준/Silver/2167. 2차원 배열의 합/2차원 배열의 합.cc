#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using std::cin;
using std::cout;

int n, m, q;
int arr[305][305];

int sum(int r1, int c1, int r2, int c2) {
	//cout << r1 << ' ' << c1 << ' ' << r2 << ' ' << c2 << '\n';
	int a = arr[r2][c2];
	int b = r1 ? arr[r1 - 1][c2] : 0;
	int c = c1 ? arr[r2][c1 - 1] : 0;
	int d = !c1 || !r1 ? 0 : arr[r1 - 1][c1 - 1];
	
	//cout << "a: " << a << " b: " << b << " c: " << c << " d: " << d << '\n';

	return a - b - c + d;
}

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> arr[i][j];

	cin >> q;
}

void run() {
	// accumulate sum
	// row
	for (int i = 0; i < n; ++i)
		for (int j = 1; j < m; ++j)
			arr[i][j] += arr[i][j - 1];

	// col
	for (int i = 1; i < n; ++i)
		for (int j = 0; j < m; ++j)
			arr[i][j] += arr[i - 1][j];

	


	int x, y, z, w;
	for (int i = 0; i < q; ++i) {
		cin >> x >> y >> z >> w;
		--x, --y, --z, --w;
		cout << sum(x, y, z, w) << '\n';
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	std::ios::sync_with_stdio(0), cin.tie(0);
	input();
	run();
}