#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::max;
using std::abs;

int arr[15], ans;

int main() {
	std::ios::sync_with_stdio(0), cin.tie(0);

	for (int i = 0; i < 10; ++i) cin >> arr[i];
	for (int i = 1; i < 10; ++i) arr[i] += arr[i - 1];

	for (int i = 0; i < 10; ++i) 
		if(abs(100 - ans) >= abs(100 - arr[i])) ans = arr[i];
	

	cout << ans;
}