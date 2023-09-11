#include <iostream>

using std::cin;
using std::cout;

int arr[100'005], n;

inline int abs(int x) {
	return x > 0 ? x : -x;
}

int main() {
	std::ios::sync_with_stdio(0), cin.tie(0);

	cin >> n;
	for(int i = 0; i < n; ++i) cin >> arr[i];

	int l = 0, r = n - 1;
	int x, y, ans = 21e8, sum;
	while(l < r) {
		sum = arr[l] + arr[r];
		if(!sum) {
			x = l, y = r;
		}
		if(abs(sum) <= ans) {
			ans = abs(sum);
			x = l, y = r;
		}

		if(sum > 0) --r;
		else ++l;
	}

	cout << arr[x] << ' ' << arr[y];
}