#include <iostream>

using std::cin;
using std::cout;

int arr[1'000'000], n, m;

bool binary_search(const int x) {
	// 구간 [l, r) -> false 인 가능성이 있는 "미확인" 구간
	// 첫 번째 true 찾기!
	register int l = 0, r = n, mid;

	while (l < r) {
		mid = l + ((r - l) >> 1);
		
		arr[mid] >= x ? r = mid : l = mid + 1;
	}

	return arr[l] == x;
}

int main() {
	// freopen("input.in", "r", stdin);
	std::ios::sync_with_stdio(0), cin.tie(0);

	int cnt, x;
	while (true) {
		cin >> n >> m;
		if (n == 0 && m == 0) break;

		for (int i = 0; i < n; ++i)
			cin >> arr[i];

		cnt = 0;
		for (int i = 0; i < m; ++i) {
			cin >> x;
			cnt += binary_search(x);
		}
		cout << cnt << '\n';
	}
	
	return 0;
}