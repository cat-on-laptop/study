#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::max;
typedef long long ll;

int arr[100005];
ll forward[100005], backward[100005], ans;
int n;

int main() {
	std::ios::sync_with_stdio(0), cin.tie(0);

	// input
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> arr[i];

	// forward prefix sum
	forward[0] = arr[0];
	for (int i = 1; i < n; ++i) forward[i] = forward[i - 1] + arr[i];

	// backward prefix sum;
	backward[n - 1] = arr[n - 1];
	for (int i = n - 2; i >= 0; --i) backward[i] = backward[i + 1] + arr[i];

	// 벌 벌 꿀
	const ll temp = backward[0] - arr[0];
	for (int i = 1; i < n - 1; ++i) 
		ans = max(ans, (temp - arr[i] + backward[i] - arr[i]));
	
	// 꿀 벌 벌
	const ll temp2 = forward[n - 1] - arr[n - 1];
	for (int i = n - 2; i > 0; --i)
		ans = max(ans, (temp2 - arr[i] + forward[i] - arr[i]));

	// 벌 꿀 벌
	for (int i = 1; i < n - 1; ++i)
		ans = max(ans, (forward[i] - arr[0] + backward[i] - arr[n - 1]));

	cout << ans << '\n';


}