#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <stack>

using std::stack;

int n, arr[80'005];
stack<int> st;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d ", arr + i);

	long long cnt = 0;

	for (int i = 0; i < n; ++i) {
		while (!st.empty() && st.top() <= arr[i])
			st.pop();

		cnt += st.size();
		st.emplace(arr[i]);
	}

	printf("%lld", cnt);
}