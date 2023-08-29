#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::vector;
using std::pair;
using std::min;

vector<pair<int, int>> core;
int arr[12][12], n, ans, maxCnt;

const int dir[4][2] = { -1,0, 1,0, 0,-1, 0,1 };

void init() {
	core.clear();
	ans = maxCnt = 0;
}

void input() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			cin >> arr[i][j];
			if (arr[i][j]) {
				if (i == 0 || j == 0 || i == n - 1 || j == n - 1) ++ans;
				else core.emplace_back(i, j);
			}
		}
}

int extend(pair<int, int> x, int d) {
	int row = x.first + dir[d][0], col = x.second + dir[d][1];
	int result = 0;

	// check if it is valid
	while (0 <= row && row < n && 0 <= col && col < n) {
		if (arr[row][col]) return -1;
		row += dir[d][0];
		col += dir[d][1];
	}

	// extend
	row = x.first + dir[d][0], col = x.second + dir[d][1];

	while (0 <= row && row < n && 0 <= col && col < n) {
		arr[row][col] = 2;
		row += dir[d][0], col += dir[d][1];
		++result;
	}
	return result;
}

void restore(pair<int, int>x, int d) {
	int row = x.first + dir[d][0], col = x.second + dir[d][1];

	while (0 <= row && row < n && 0 <= col && col < n) {
		arr[row][col] = 0;
		row += dir[d][0], col += dir[d][1];
		
	}
}


void dfs(int curr, int len, int cnt) {
	// curr := 몇 번째로 연결할 코어인지(현재 보는 코어)
	// len := 이때까지 사용한 전선의 길이
	// cnt := 연결한 코어의 수

	// curr번부터 시작해서 남은 코어를 모두 연결하는 경우의 수를 탐색
	if (cnt > maxCnt) ans = len, maxCnt = cnt;
	else if (cnt == maxCnt) ans = min(len, ans);

	if (curr == core.size()) return;


	// 4방향 선택
	for (int d = 0; d < 4; ++d) {
		int nr = core[curr].first + dir[d][0];
		int nc = core[curr].second + dir[d][1];

		int wire = extend(core[curr], d);

		if (wire == -1) continue;

		dfs(curr + 1, len + wire, cnt + 1);
		restore(core[curr], d);
	}
	

	// 연결 x
	dfs(curr + 1, len, cnt);
}

void run() {
	dfs(0, 0, 0);
}

int main() {
	// freopen("input.txt", "r", stdin);
	std::ios::sync_with_stdio(0), cin.tie(0);

	int t; cin >> t;

	for (int tc = 1; tc <= t; ++tc) {
		init();
		input();
		run();
		cout << "#" << tc << ' ' << ans << '\n';

	}
}