#include <iostream>

using std::cin;
using std::cout;

bool prime[1'000'005];

int main() {
	int n; cin >> n;

	// sieve of eratosthenes
	prime[0] = prime[1] = true;
	for (int i = 2; i < 1'000'000 / i; ++i) {
		if (prime[i]) continue;
		for (int j = i * i; j <= 1'000'000; j += i)
			prime[j] = true;
	}

	if (n < 8) {
		// 8 미만이면 가망 x
		// 8 -> 2 2 2 2
		cout << -1;
		return 0;
	}
	if (n & 1) {
		// 홀수면 가장 작은 소수 두 개 우선 출력
		cout << "2 3 ";
		n -= 5;
	}
	else {
		// 짝수면 가장 작손 소수 두 개 우선 출력
		cout << "2 2 ";
		n -= 4;
	}
	
	// Goldbach's conjecture
	for (int i = 2; i <= n >> 1; ++i) {
		if (!prime[i] && !prime[n - i]) {
			cout << i << ' ' << n - i;
			return 0;
		}
	}

	return 0;
}