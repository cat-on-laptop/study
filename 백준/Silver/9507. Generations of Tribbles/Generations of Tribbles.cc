#include <iostream>

using std::cin;
using std::cout;

int main() {
	int t;
	long long dp[68];

	for (int i = 0; i <= 67; ++i) {
		if (i < 2) dp[i] = 1;
		else if (i == 2) dp[i] = 2;
		else if (i == 3) dp[i] = 4;
		else dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4];
	}

	cin >> t;
	for (int i = 0; i < t; ++i) {
		int n; cin >> n;
		cout << dp[n] << '\n';
	}
	return 0;
}