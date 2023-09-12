#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

bool prime[4'000'005];
vector<int> arr;

int main() {
	std::ios::sync_with_stdio(0), cin.tie(0);

	// Sieve of Eratosthenes
	prime[0] = prime[1] = true;
	for (int i = 2; i <= 4'000'000 / i; ++i) {
		if (prime[i]) continue;

		for (int j = i * i; j <= 4'000'000; j += i)
			prime[j] = true;
	}

	// input
	int n, cnt = 0; cin >> n;

	for (int i = 0; i <= n; ++i) if(!prime[i]) arr.emplace_back(i);

	
	register int l = 0, r = 0, sum = 0;
	// r은 구간의 길이 + 1;
	int len = (int)arr.size();

	// two pointer로 구간합이 n이되면 cnt ++ 이거 구현하기...시입러..
	while (r <= len) {
		if (sum < n) {
			if (r == len) break;
			sum += arr[r++];
		}
		else if (sum > n) sum -= arr[l++];
		else {
			++cnt;
			sum -= arr[l++];
		}
	}
	cout << cnt;

	int db = 1;
}