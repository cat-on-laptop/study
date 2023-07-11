#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int arr[15][15];
int cnt[15][15];
int n, sc, sr, ec, er;

struct state_s {
    int row, col, time;

    state_s(int _row, int _col, int _time) : row(_row), col(_col), time(_time) {}
};

int main() {
	// freopen("input.txt", "r", stdin);
    int t; cin >> t;
    for(int tc = 1; tc <= t; ++tc) {
        cin >> n;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                cin >> arr[i][j];
                cnt[i][j] = 0x7fffffff;
            }
        }
        cin >> sr >> sc >> er >> ec;
        cnt[sr][sc] = 0;

        queue<state_s> q;
        q.push(state_s(sr, sc, 0));
	
        while(!q.empty()) {
            state_s curr = q.front(); q.pop();
            int row = curr.row, col = curr.col, time = curr.time;
			// printf("curr : <%d, %d, %d>\n", row, col ,time);

            // 도착한 경우
            if(row == er && col == ec) {
                cnt[er][ec] = cnt[er][ec] > time ? time : cnt[er][ec];
                continue;    
            }

            for(int d = 0; d < 4; ++d) {
                int nr = row + dir[d][0], nc = col + dir[d][1];

                if(0 > nr || nr >= n || 0 > nc || nc >= n) continue;

                // 새로 갈 곳의 값이 현재 값보다 작으면 갈 필요 x
                if(cnt[nr][nc] <= cnt[row][col] + 1) continue;

				// 새로 갈 곳이 장애물이 있는 경우 pass
				if(arr[nr][nc] == 1) continue;

				// 새로 갈 곳이 0인 경우는 바로 +1 넣어줌
				if(arr[nr][nc] == 0) {
					q.push(state_s(nr, nc, time + 1));
					cnt[nr][nc] = time + 1;
				}

				// 새로 갈 곳이 소용돌이인 경우
				else {
					// 현재 시간이 % 3 == 2이면 소용돌이가 없으므로 이동 가능
					if(time % 3 == 2) {
						q.push(state_s(nr, nc, time + 1));
						cnt[nr][nc] = time + 1;
					}
					else {
						int temp = 1;
						// time + temp를 나눈 나머지가 2가 될 때까지 temp +
						while((time + temp) % 3 != 2) ++temp;
						
						if(cnt[nr][nc] > time + temp + 1) {
							// 기다린 후 이동 time + temp + 1이 더 작아야 이동에 의미가 있음
							cnt[nr][nc] = time + temp + 1;
							q.push(state_s(nr, nc, cnt[nr][nc]));
						}

					}
				}
            }

        }

		cout << "#" << tc << ' ';
		cnt[er][ec] == 0x7fffffff ? cout << -1 : cout << cnt[er][ec];
		cout << endl;
    }
}