#include <iostream>
#include <vector>
#define MOD 1'000'000'007

using std::cin;
using std::cout;
using std::vector;

typedef vector<vector<long long>> matrix_t;

matrix_t arr, ans;
int n, m, x;

matrix_t operator*(const matrix_t& x, const matrix_t& y) {
	matrix_t rst = vector<vector<long long>>(n, vector<long long>(n, 0));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < n; ++k) {
				rst[i][j] += x[i][k] * y[j][k];
				rst[i][j] %= MOD;
			}
		}
	}

	return rst;
}

int main() {
	std::ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	arr = vector<vector<long long>>(n, vector<long long>(n, 0));
	ans = vector<vector<long long>>(n, vector<long long>(n, 0));
	for (int i = 0; i < n; ++i) ans[i][i] = 1;
	for (int i = 0; i < m; ++i) {
		int x, y; cin >> x >> y; --x, --y;
		arr[x][y] = arr[y][x] = 1;
	}
	cin >> x;

	while (x > 0) {
		if (x & 1) ans = ans * arr;

		arr = arr * arr;
		x >>= 1;
	}

	cout << ans[0][0];
}