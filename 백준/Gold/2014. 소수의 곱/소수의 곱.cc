#include <iostream>
#include <queue>
#include <functional>

using std::cin;
using std::cout;
using std::priority_queue;

int candidate[100], n, k, prev, cnt;
//long long arr[100'000];
priority_queue<int, std::vector<int>, std::greater<int>> pq;

int main() {
	std::ios::sync_with_stdio(0), cin.tie(0);

	cin >> k >> n;

	for (int i = 0; i < k; ++i) 
		cin >> candidate[i];
	
	pq.emplace(1);
	while (cnt != n + 1) {
		long long curr = pq.top(); pq.pop();
		if (curr == prev) continue;

		prev = curr; ++cnt;

		for (int i = 0; i < k; ++i) {
			if (curr * candidate[i] > 0x7fffffff) continue;
			pq.emplace(curr * candidate[i]);
		}
	}
	cout << prev;
}