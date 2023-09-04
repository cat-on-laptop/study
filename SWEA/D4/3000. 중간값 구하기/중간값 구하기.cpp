#include <iostream>

using std::cin;
using std::cout;

int n, minCnt, maxCnt;
int maxHeap[200005];
int minHeap[200005];
const int mod = 20171109;

int min_top() {
	return minHeap[1];
}

int max_top() {
	return maxHeap[1];
}

void min_push(int val) {
	minHeap[++minCnt] = val;
	int idx = minCnt, temp;
	while (idx > 1) {
		if (minHeap[idx >> 1] > minHeap[idx]) {
			temp = minHeap[idx >> 1];
			minHeap[idx >> 1] = minHeap[idx];
			minHeap[idx] = temp;
			idx >>= 1;
		}
		else break;
	}
}

void max_push(int val) {
	maxHeap[++maxCnt] = val;
	int idx = maxCnt, temp;
	while (idx > 1) {
		if (maxHeap[idx >> 1] < maxHeap[idx]) {
			temp = maxHeap[idx >> 1];
			maxHeap[idx >> 1] = maxHeap[idx];
			maxHeap[idx] = temp;
			idx >>= 1;
		}
		else break;
	}
}

void min_pop() {
	minHeap[1] = minHeap[minCnt--];

	int curr = 1;
	while ((curr << 1) <= minCnt) { // 자식이 있다면
		int child;
		
		if ((curr << 1) == minCnt) // 왼쪽 자식만 있다면
			child = curr << 1;
		else // 둘 중 더 작은 것을 선택해야 minHeap 성질 유지
			child = minHeap[(curr << 1)] < minHeap[(curr << 1) + 1] ? curr << 1 : (curr << 1) + 1;

		if (minHeap[curr] < minHeap[child]) break;

		int temp = minHeap[child];
		minHeap[child] = minHeap[curr];
		minHeap[curr] = temp;
		curr = child;
	}
}

void max_pop() {
	maxHeap[1] = maxHeap[maxCnt--];

	int curr = 1;
	while ((curr << 1) <= maxCnt) { // 자식이 있다면
		int child;

		if ((curr << 1) == maxCnt) // 왼쪽 자식만 있다면
			child = curr << 1;
		else // 둘 중 더 작은 것을 선택해야 minHeap 성질 유지
			child = maxHeap[(curr << 1)] > maxHeap[(curr << 1) + 1] ? curr << 1 : (curr << 1) + 1;

		if (maxHeap[curr] > maxHeap[child]) break;

		int temp = maxHeap[child];
		maxHeap[child] = maxHeap[curr];
		maxHeap[curr] = temp;
		curr = child;
	}
}

int main() {
	std::ios::sync_with_stdio(0), cin.tie(0);
	int t; cin >> t;

	for (int tc = 1; tc <= t; ++tc) {
		// init
		int ans = 0;
		minCnt = maxCnt = 0;
		cin >> n;

		int x, y;
		cin >> x;
		max_push(x);

		for (int i = 0; i < n; ++i) {
			cin >> x >> y;
			if (x > y) {
				min_push(x);
				max_push(y);
			}
			else {
				min_push(y);
				max_push(x);
			}

			while (min_top() < max_top()) {
				int min = min_top();
				int max = max_top();
				min_pop(); max_pop();
				min_push(max);
				max_push(min);
			}

			ans = (ans + max_top()) % mod;

		}
		cout << '#' << tc << ' ' << ans << '\n';
	}
}