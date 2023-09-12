#include <iostream>
#include <vector>
#define MOD 1'000'000'007

using std::cin;
using std::cout;
using std::vector;

typedef vector<vector<long long>> matrix_t;

matrix_t arr = {
	{0,1,1,0,0,0,0,0},
	{1,0,1,1,0,0,0,0},
	{1,1,0,1,1,0,0,0},
	{0,1,1,0,1,1,0,0},
	{0,0,1,1,0,1,1,0},
	{0,0,0,1,1,0,0,1},
	{0,0,0,0,1,0,0,1},
	{0,0,0,0,0,1,1,0}
};

matrix_t ans = vector<vector<long long>>(8, vector<long long>(8, 0));

matrix_t operator*(const matrix_t& x, const matrix_t& y) {
	matrix_t rst = vector<vector<long long>>(8, vector<long long>(8, 0));

	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			for (int k = 0; k < 8; ++k) {
				rst[i][j] += x[i][k] * y[k][j];
				rst[i][j] %= MOD;
			}
		}
	}

	return rst;
}

int main() {
	for (int i = 0; i < 8; ++i) ans[i][i] = 1;
	int n; cin >> n;

	while (n > 0) {
		if (n & 1) ans = ans * arr;

		arr = arr * arr;
		n >>= 1;
	}

	cout << ans[0][0];
}