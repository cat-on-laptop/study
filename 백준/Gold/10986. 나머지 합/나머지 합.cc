#include <iostream>
typedef long long ll;

using std::cin;
using std::cout;

ll arr[1000005];
int mod[1005];
int n, m;

int main() {
	std::ios::sync_with_stdio(0), cin.tie(0);
	ll cnt = 0;

	cin >> n >> m;
	for (int i = 0; i < n; ++i) 
		cin >> arr[i];
	
	for (int i = 1; i < n; ++i) arr[i] += arr[i - 1];
	
	for (int i = 0; i < n; ++i) mod[arr[i] % m]++;

	for (int i = 0; i < m; ++i) cnt += ((long long)mod[i] * (mod[i] - 1)) >> 1;
	cnt += mod[0];

	cout << cnt;
	
}