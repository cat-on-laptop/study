#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 10005

using std::cin;
using std::cout;
using std::vector;
using std::sort;

int n;
vector<int> arr;

void input() {
	cin >> n;
	arr = vector<int>(n);
	for (int i = 0; i < n; ++i) cin >> arr[i];
}

inline int abs(int x) {
	return x > 0 ? x : -x;
}

void run() {
	sort(arr.begin(), arr.end());

	register int l = 0, r = n - 1;
	int x, y, ans = 21e8, sum;
	while (l < r) {
		sum = arr[l] + arr[r];
		if (!sum) {
			x = l, y = r; 
			break;
		}

		if (abs(sum) < ans) {
			ans = abs(sum);
			x = l, y = r;
		}

		if (sum > 0) --r;
		else ++l;

	}

	cout << arr[x] << ' ' << arr[y];
}

int main() {
	std::ios::sync_with_stdio(0), cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	input();
	run();
}