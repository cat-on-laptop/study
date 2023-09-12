#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using std::cin;
using std::cout;
using std::sort;
using std::priority_queue;
using std::vector;

struct gem_t {
	int m, v;

	gem_t(int _m = 0, int _v = 0) : m(_m), v(_v) {}

	bool operator<(const gem_t& x) const {
		return v < x.v;
	}
};

vector<gem_t> arr;
int bag[300'005], n, k;

void input() {
	cin >> n >> k;
	int m, v;
	for (int i = 0; i < n; ++i) {
		cin >> m >> v;
		arr.emplace_back(m, v);
	}

	for (int i = 0; i < k; ++i) cin >> bag[i];
}

void run() {
	sort(bag, bag + k); // 가방을 크기 순으로 정렬
	sort(arr.begin(), arr.end(), [](const gem_t& x, const gem_t& y) { return x.m < y.m; }); // 보석을 크기 순으로 정렬
	int idx = 0; // 보석을 가리키는 idx

	priority_queue<gem_t> pq;
	long long ans = 0;

	for (int i = 0; i < k; ++i) {
		for (; idx < n && arr[idx].m <= bag[i]; ++idx) pq.emplace(arr[idx]);
	
		if (!pq.empty()) {
			ans += pq.top().v; pq.pop();
		}
	}

	cout << ans;
}

int main() {
	std::ios::sync_with_stdio(0), cin.tie(0);
	input();
	run();
}