#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

vector<int> arr[1'005];
int b[1'005], visited[1'005]; // b[i] := i번 일을 하는 직원의 number
int n, m, cnt;

bool dfs(int curr) {
	if (visited[curr] == cnt) // 현재 수행 횟수에서 방문한 적이 있다면 false
		return false;

	visited[curr] = cnt; // 현재 수행 횟수에서 방문 처리

	for(const int&x : arr[curr]) {
		if(!b[x] || dfs(b[x])) { 
		// x번 일을 담당하는 직원이 없거나
		// x번 일을 담당하는 직원을 옮겨서 가능하다면
			b[x] = curr;
			return true;
		}
	}
	
	return false;
}

int main() {
	// freopen("input.in", "r", stdin);
	std::ios::sync_with_stdio(0), cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		int x; cin >> x;
		for (int j = 0; j < x; ++j) {
			int temp; cin >> temp;
			arr[i+1].emplace_back(temp);
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; ++i) { // 두 번 일을 할 수 있으므로 biparate matching을 두 번 돌려줌.
		++cnt; if (dfs(i)) ++ans;
		++cnt; if (dfs(i)) ++ans;
	}

	cout << ans;

	return 0;
}