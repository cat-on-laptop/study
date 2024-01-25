#include <iostream>
#include <vector>
#include <cstring>

using std::cin;
using std::cout;
using std::vector;

vector<int> arr[205];
int b[205]; // b[i] : i번 축사에 들어간 소의 넘버
bool visited[205];
int n, m;

bool dfs(int x) {
	for (const int& curr : arr[x]) {
		if (visited[curr]) continue;
		visited[curr] = true;

		if (b[curr] == 0 || dfs(b[curr])) { 
			// curr가 매칭이 안되어 있거나, 기존에 매칭되 있던 것을 지우고 새로 매칭이 가능한 경우
			b[curr] = x;
			return true;
		}
	}
	return false;
}

int main() {
	// freopen("input.in", "r", stdin);
	std::ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;

	for (int i = 1; i <= n; ++i) {
		int s, x; cin >> s;
		for (int j = 0; j < s; ++j) {
			cin >> x;
			arr[i].emplace_back(x);
		}
	}

	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		memset(visited, 0, sizeof(visited));
		if (dfs(i)) ++cnt;
	}

	cout << cnt << '\n';
	return 0;
}