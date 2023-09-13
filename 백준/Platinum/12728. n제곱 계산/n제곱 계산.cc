#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>

using std::vector;

typedef vector<vector<int>> matrix_t;

matrix_t operator*(const matrix_t& x, const matrix_t& y) {
	matrix_t ret = vector<vector<int>>(2, vector<int>(2));

	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j) {
			for (int k = 0; k < 2; ++k)
				ret[i][j] += x[i][k] * y[k][j];
			ret[i][j] %= 1000;
		}
	return ret;
}

int main() {
	int t; scanf("%d", &t);

	for (int tc = 1; tc <= t; ++tc) {
		matrix_t e = vector<vector<int>>(2, vector<int>(2, 0));
		for (int i = 0; i < 2; ++i) e[i][i] = 1;
		matrix_t x = { {3, 5}, {1, 3} };
		int n; scanf("%d", &n);

		while (n) {
			if (n & 1) e = e * x;
			x = x * x;
			n >>= 1;
		}
		
		printf("Case #%d: %03d\n", tc, (e[0][0] << 1) % 1'000 - 1 );
	}
}
