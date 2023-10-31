#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);

	int n, x; cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x; 
		arr.push_back(x);
	}

	sort(arr.begin(), arr.end(), greater<int>());

	for (const int& x : arr)
		cout << x << '\n';
}