#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using std::cin;
using std::cout;

int n, h, arr[500005];

int main() {
	// freopen("input.txt", "r", stdin);
	std::ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> h;
	int x;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		if (i & 1) { // 종유석
			--arr[h];
			++arr[h - x];
		}
		else {
			++arr[0];
			--arr[x];
		}
	}

	// imos
	for (int i = 1; i < h; ++i) arr[i] += arr[i - 1];

	int val = 0x7fffffff, cnt = 0;

	for (int i = 0; i < h; ++i) {
		if (val > arr[i]) {
			val = arr[i]; cnt = 1;
		}
		else if (val == arr[i]) ++cnt;
	}

	cout << val << ' ' << cnt;
}