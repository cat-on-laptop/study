#include <iostream>
#include <cstring>
#define endl '\n'
#define MAX 25

using namespace std;

int n, arr[MAX][MAX], ans;
bool visited[105];
const int dir[4][2] = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};

inline int max(int x, int y) {
	return x > y ? x : y;
}

void init() {
	// reset values
	ans = 0x80000000;
}

void input() {
	cin >> n;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			cin >> arr[i][j];
}

int check(int row, int col, int x, int y) {
	// check := row, col에서 시작하여 \ 방향으로 x만큼 , / 방향으로 y만큼 진행하여 먹은 디저트의 개수를 리턴하는 함수
	
	memset(visited, false, sizeof(visited)); // 매 탐색마다 visited는 리셋 되어야 함
	
	int cnt = 0;
	// int cnt = 1; // 먹은 디저트의 개수를 저장할 변수 cnt
	// visited[arr[row][col]] = true; // 현재 자리는 먹었으니 cnt를 1로, visited는 true로

	for(int d = 0; d < 4; ++d) {
		int l;
		if(d & 1) l = y; // / 방향
		else l = x; // \ 방향

		for(int i = 0; i < l; ++i) {
			row = row + dir[d][0], col = col + dir[d][1]; // 새 cafe 탐색

			if(0 > row || row >= n || 0 > col || col >= n) return 0; // 범위를 벗어나면 x
			if(visited[arr[row][col]]) return 0; // 이미 방문했던 cafe는 안됨
			

			visited[arr[row][col]] = true;
			++cnt;
		}
		// printf("arr[%d][%d] = %d, cnt = %d\n", row, col, arr[row][col], cnt);
	}
	return cnt;
}

int main(void) {
	ios::sync_with_stdio(0), cin.tie(0);

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	int T; cin >> T;

	for(int tc = 1; tc <= T; ++tc) {
		init();
		input();

		// 우하단 좌하단 좌상단 우상단 으로 탐색할 것이기 때문에 1열부터, n-2열 까지만 탐색하면 됨
		// 행의 경우 0번행 ~ n-2번 행까지만 탐색하면 됨

		for(int row = 0; row < n-1; ++row)
			for(int col = 1; col < n-1; ++col) 
				// row, col을 맨 위로 하는 마름모에 대하여 탐색
				// \ / 방향으로 가는데 갈 수 있는 최대 길이는 n-1
				for(int x = 1; x < n; ++x)
					for(int y = 1; y < n; ++y) {
						int temp = check(row, col, x, y);
						
						if(temp > 0) ans = max(temp, ans);
					}
			
		
		if(ans < 0) ans = -1;

		cout << "#" << tc << ' ' << ans << endl;
	}
}